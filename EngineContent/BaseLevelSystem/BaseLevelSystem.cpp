#include "BaseLevelSystem.h"
#include "../EngineSettings/EngineSettings.h"

map<string, function<BaseEntity*()>> BaseLevelSystem::EntitySpawnDataStorage;
map<string, function<RenderingModifier* ()>> BaseLevelSystem::MaterialDataStorage;
BaseEntity_RenderingInfo BaseLevelSystem::RenderingDataDump;

string BaseLevelSystem::ImproveFormatting(string Input)
{
    string Output = Input;

    for (int i = 0; i < Output.size(); i++)
    {
        try
        {
            if (i > -1)
            {
                if (Output[i] == ' ' || Output[i] == '\t' || Output[i] == '\n' || Output[i] == '\r')
                {
                    Output.erase(Output.begin() + i);
                }
            }
        }
        catch (...) {}
    }

    return Output;
}

vector<string> BaseLevelSystem::ExtractViaComma(string Input)
{
    Input += ",";  //it splits a string up by a charter btw
    vector<string> Output;

    while (Input.find(",") != string::npos)
    {
        Output.push_back(Input.substr(0, Input.find(",")));
        Input = Input.substr(Input.find(","), Input.length());
    }

    return Output;
}


template<typename T>
void BaseLevelSystem::RegisterEntitySpawnData(string ClassId )
{
    BaseEntity SpawnEnt = []()
        {
            T NewEnt = new T();
            return NewEnt;
        };

    EntitySpawnDataStorage[ClassId] = & SpawnEnt;
}

template<typename T>
void BaseLevelSystem::RegisterMaterialData(string MaterialId)
{
    RenderingModifier SpawnEnt = []()
        {
            T NewEnt = new T();
            return NewEnt;
        };

    MaterialDataStorage[MaterialId] = &SpawnEnt;
}



BaseEntity* BaseLevelSystem::CreateNewEntity(string ClassId)
{
    if (EntitySpawnDataStorage.count(ClassId) > 0)
    {
        return EntitySpawnDataStorage[ClassId]();
    }

    return nullptr;
}

RenderingModifier* BaseLevelSystem::CreateNewMaterialInstance(string MaterialId)
{
    if (MaterialDataStorage.count(MaterialId) > 0)
    {
        return MaterialDataStorage[MaterialId]();
    }

    return nullptr;
}


BaseEntity_RenderingInfo BaseLevelSystem::CollectRenderingData()
{
    BaseEntity_RenderingInfo Copy = RenderingDataDump;
    RenderingDataDump = BaseEntity_RenderingInfo();
    return Copy;
}

void BaseLevelSystem::RequestEntityToCollectRendingData(BaseEntity* Ent)
{
    Ent->Fire( "CollectRenderingDataFromBaseLevelSystem", "1" );
}


void BaseLevelSystem::LoadLevel(string PathToAssest)
{
    ifstream File("PathToAssest");
    string Line;

    vector<string> ToVector = vector<string>();

    for (string Line; getline(File, Line); )
    {
        ToVector.push_back(Line);
    }

    BaseLevelSystem::LoadLevel(ToVector);
}

void BaseLevelSystem::LoadLevel(vector<string> LevelAssestAsVector)
{
    int IncaspulationLevel = 0;
    string Processes[8];

    BaseEntity* Ent = nullptr;

    for (int i = 0; i < LevelAssestAsVector.size(); i++)
    {
        string CurrentLine = LevelAssestAsVector[i];

        if (IncaspulationLevel == 0) { Processes[0] = BaseLevelSystem::ImproveFormatting(CurrentLine); } //set as root process
        if (CurrentLine.find("{") != string::npos) { IncaspulationLevel++; } //incapsulate

        if (Processes[0] == "Entities")
        {
            if (IncaspulationLevel == 1) //creates an entity
            {
                Ent = BaseLevelSystem::CreateNewEntity(BaseLevelSystem::ImproveFormatting(CurrentLine));
                BaseEntity::Spawn(Ent);
            }

            if (IncaspulationLevel == 2 && Ent != nullptr) // adds key values to that entity
            {
                if (CurrentLine.find("=") != string::npos)
                {
                    string Key = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(0, CurrentLine.find("=") - 1));
                    string Value = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(CurrentLine.find("=") +1, CurrentLine.size() -CurrentLine.find("=") ));

                    Ent->SetKeyValue(Key, Value);
                }
                else
                {
                    Processes[1] = BaseLevelSystem::ImproveFormatting(CurrentLine);
                }
            }

            if (IncaspulationLevel == 3 && Processes[1] == "Rendering" && Ent != nullptr) // adds rendering data
            {
                if (CurrentLine.find("=") != string::npos)
                {
                    string Key = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(0, CurrentLine.find("=") - 1));
                    string Value = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(CurrentLine.find("=") + 1, CurrentLine.size() - CurrentLine.find("=")));

                    if (Key == "MyModifyer")
                    {
                        RenderingDataDump.MyModifyer = BaseLevelSystem::CreateNewMaterialInstance( Value );
                    } 
                    else if (Key == "Importance")
                    {
                        try
                        {
                            RenderingDataDump.Importance = stoi(Value);
                        }
                        catch (...) {}
                    }
                    else if (Key == "OffsetX")
                    {
                        try
                        {
                            RenderingDataDump.OffsetX = stoi(Value);
                        }
                        catch (...) {}
                    }
                    else if (Key == "OffsetY")
                    {
                        try
                        {
                            RenderingDataDump.OffsetY = stoi(Value);
                        }
                        catch (...) {}
                    }
                    else if (Key == "Contents")
                    {
                        Processes[2] = "Contents";
                    }
                }

                if (CurrentLine.find("}") != string::npos) //tells the ent that there rendering data is redy for collection
                {
                    BaseLevelSystem::RequestEntityToCollectRendingData(Ent);
                }
            }

            if (IncaspulationLevel == 4 && Processes[2] == "Contents" && Ent != nullptr) // adds rendering contents ...imagine this is in the first bracket you see above as that is easier to understand
            {
                RenderingDataDump.ContentsToRender.push_back(CurrentLine);
            }

            if (IncaspulationLevel == 3 && Processes[1] == "Fire" && Ent != nullptr) //fires to
            {
                if (CurrentLine.find("=") != string::npos)
                {
                    string Message = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(0, CurrentLine.find("=") - 1));
                    string Value = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(CurrentLine.find("=") + 1, CurrentLine.size() - CurrentLine.find("=")));

                    Ent->Fire(Message, Value);
                }
            }

            if (IncaspulationLevel == 3 && Processes[1] == "FireOut" && Ent != nullptr) //fires out
            {
                if (CurrentLine.find(",") != string::npos)
                {
                    vector<string> Data = BaseLevelSystem::ExtractViaComma(BaseLevelSystem::ImproveFormatting(CurrentLine));

                    if (Data.size() >= 4)
                    {
                        vector<BaseEntity*> Ents = BaseEntity::GetEntitiesByKeyValue("Name", Data[0]);

                        for (int i = 0; i < Ents.size(); i++)
                        {
                            Ent->AddFireOut(Ents[i], Data[1], Data[2], Data[3]);
                        }
                    }
                }
            }

        }

        if (Processes[0] == "Commands") //runs commands
        {
            if (CurrentLine.find("=") != string::npos)
            {
                string Message = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(0, CurrentLine.find("=") - 1));
                string Value = BaseLevelSystem::ImproveFormatting(CurrentLine.substr(CurrentLine.find("=") + 1, CurrentLine.size() - CurrentLine.find("=")));

                EngineSettings::GetConstValue("CommandConsoleCMD", TYPE_REP(BaseEntity))->Fire(Message, Value);
            }
            else
            {
                EngineSettings::GetConstValue("CommandConsoleCMD", TYPE_REP(BaseEntity))->Fire(BaseLevelSystem::ImproveFormatting(CurrentLine), "1");
            }
        }


        if (CurrentLine.find("}") != string::npos) { IncaspulationLevel--; }
    }
}

void BaseLevelSystem::UnLoadLevel()
{
    BaseEntity::RemoveAll();

    EngineSettings::ChangeInRunTime("RenderOffsetX", 0);
    EngineSettings::ChangeInRunTime("RenderOffsetY", 0);

    delete EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(RenderingModifier));
    EngineSettings::ChangeInRunTime("PostPorcessingShader", nullptr);
}

