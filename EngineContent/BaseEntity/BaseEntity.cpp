#include "BaseEntity.h"

vector<BaseEntity *> BaseEntity::EntityiesInRunTime;

void BaseEntity::Update(float DeltaTime)
{
}

void BaseEntity::Start()
{
}

void BaseEntity::ReceiveFireInstruction(string Message, string Value)
{
}


void BaseEntity::Fire(string Message, string Value)
{
	ReceiveFireInstruction(Message, Value);

	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			MyComponents[i].ReceiveFireInstruction(Message, Value);
		}
		catch (...) {}
	}
}


void BaseEntity::SetKeyValue(string Key, string value)
{
	KeyValueList[Key] = value;
}

string BaseEntity::GetValueOfKey(string Key)
{
	if (KeyValueList.count(Key) > 0)
	{
		return KeyValueList[Key]; 
	}
	else
	{
		return STR_NULL; //it dosent exsist
	}
}


void BaseEntity::AddComponent(BaseComponent& Com)
{
	Com.SelfOwner = this; //so the component knows who its boss is
	MyComponents.push_back(Com);
	Com.Start();
}

BaseComponent &BaseEntity::GetComponent(string Identifyer) //get component by identifyer
{
	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			if (MyComponents[i].GetIdentifyer() == Identifyer) //found what we are looking for
			{
				return MyComponents[i];
			}
		}
		catch (...) {}
	}
}

void BaseEntity::RemoveComponent(string Identifyer) //removes a component by its idenifyer
{
	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			if (MyComponents[i].GetIdentifyer() == Identifyer) //found what we are looking for
			{
				MyComponents.erase(MyComponents.begin() + i);
				return;
			}
		}
		catch (...) {}
	}
}


void BaseEntity::Spawn() //puts entity in run time
{
	EntityiesInRunTime.push_back(this);
	MyIndex = EntityiesInRunTime.size() -1;
	Start(); 
}

void BaseEntity::Remove() //removes self/this
{
	for (int i = 0; i < MyComponents.size(); i++)
	{
		MyComponents[i].SelfOwner = nullptr;
	}
	EntityiesInRunTime.erase(EntityiesInRunTime.begin() + MyIndex);
}

void BaseEntity::RemoveAll()
{
	for (int i = 0; i < EntityiesInRunTime.size(); i++) //finds all entities and removes them
	{
		try
		{
			EntityiesInRunTime[i]->Remove();
		}
		catch(...) {}
	}
}


bool BaseEntity::IsVaild(BaseEntity* Ent)
{
	try
	{
		if (Ent != nullptr)
		{
			for (int i = 0; i < EntityiesInRunTime.size(); i++)
			{
				if (EntityiesInRunTime[i] == Ent)
				{
					return true;
				}
			}
		}
		return false;
	}
	catch (...)
	{
		return false;
	}
}

void BaseEntity::ProcessUpdate(float DeltaTime)
{
	for (int i = 0; i < EntityiesInRunTime.size(); i++)
	{
		try
		{
			EntityiesInRunTime[i]->Update(DeltaTime); //updates all entities

			for (int o = 0; o < EntityiesInRunTime[i]->MyComponents.size(); o++) //then updates there components
			{
				EntityiesInRunTime[i]->MyComponents[o].SelfOwner = EntityiesInRunTime[i];
				EntityiesInRunTime[i]->MyComponents[o].Update(DeltaTime);
			}
		}
		catch (...) {}
	}
}

void BaseEntity::ProcessRendering(int X, int Y, bool NewLineAfter)
{
	int CurrentImportance = 0;
	string CurrentlyGoingToPush = "";
	RenderingModifier CurrentRenderingModifyer;

	for (int i = 0; i < EntityiesInRunTime.size(); i++)
	{
		vector<string> RenderContent = EntityiesInRunTime[i]->MyRenderingInfo.ContentsToRender;
		int OffsetX = EntityiesInRunTime[i]->MyRenderingInfo.OffsetX;
		int OffsetY = EntityiesInRunTime[i]->MyRenderingInfo.OffsetY;
		int Importance = EntityiesInRunTime[i]->MyRenderingInfo.Importance;

		if (Y - OffsetY > 0 && RenderContent.size() - 1 < Y - OffsetY) //is with in screenbounds y
		{
			if (X - OffsetX > 0 && RenderContent[Y].length() < X - OffsetX) //is with in screenbounds x
			{
				if (RenderContent[Y - OffsetY][X - OffsetX] != ' ' && Importance >= CurrentImportance) //is not an enpty pixle and is a pixle of higher importance
				{
					CurrentImportance = Importance; //sets the pixle data to the curent pixle to render
					CurrentlyGoingToPush = RenderContent[Y - OffsetY];
					CurrentRenderingModifyer = EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer;
				}
			}
		}
	}

	string NewToPush = CurrentRenderingModifyer.PreRender(); //runs the render modifyer that can be used to create stuff like flashing materials
	if (NewToPush != STR_NULL) { CurrentlyGoingToPush = NewToPush[0]; }

	cout << CurrentlyGoingToPush; //RENDERS CHARIZAL
	if (NewLineAfter == true) { cout << endl; }

	CurrentRenderingModifyer.PostRender();
}

