#include "BaseLevelSystem.h"
#include "../EngineSettings/EngineSettings.h"

map<string, function<BaseEntity*()>> BaseLevelSystem::EntitySpawnDataStorage;
map<string, function<RenderingModifier* ()>> BaseLevelSystem::MaterialDataStorage;
BaseEntity_RenderingInfo BaseLevelSystem::RenderingDataDump;

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

    MaterialDataStorage[ClassId] = &SpawnEnt;
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

void BaseLevelSystem::LoadLevel(string Path)
{
}

void BaseLevelSystem::UnLoadLevel()
{
    BaseEntity::RemoveAll();

    EngineSettings::ChangeInRunTime("RenderOffsetX", 0);
    EngineSettings::ChangeInRunTime("RenderOffsetY", 0);

    delete EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(RenderingModifier));
    EngineSettings::ChangeInRunTime("PostPorcessingShader", nullptr);
}

