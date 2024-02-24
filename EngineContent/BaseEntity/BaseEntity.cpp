#include "BaseEntity.h"

vector<BaseEntity *> BaseEntity::EntityiesInRunTime;

void BaseEntity::Update(float DeltaTime)
{
}

void BaseEntity::Start()
{
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
		return NULL;
	}
}


void BaseEntity::AddComponent(BaseComponent& Com)
{
	Com.SelfOwner = this;
	MyComponents.push_back(Com);
	Com.Start();
}

BaseComponent &BaseEntity::GetComponent(string Identifyer)
{
	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			if (MyComponents[i].Identifyer == Identifyer)
			{
				return MyComponents[i];
			}
		}
		catch (...) {}
	}
}

void BaseEntity::RemoveComponent(string Identifyer)
{
	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			if (MyComponents[i].Identifyer == Identifyer)
			{
				MyComponents.erase(MyComponents.begin() + i);
				return;
			}
		}
		catch (...) {}
	}
}


void BaseEntity::Spawn()
{
	EntityiesInRunTime.push_back(this);
	MyIndex = EntityiesInRunTime.size() -1;
	this->Spawn();
}

void BaseEntity::Remove()
{
	for (int i = 0; i < MyComponents.size(); i++)
	{
		MyComponents[i].SelfOwner = nullptr;
	}
	EntityiesInRunTime.erase(EntityiesInRunTime.begin() + MyIndex);
}

void BaseEntity::RemoveAll()
{
	for (int i = 0; i < EntityiesInRunTime.size(); i++)
	{
		try
		{
			EntityiesInRunTime[i]->Remove();
		}
		catch(...) {}
	}
}


void BaseEntity::ProcessUpdate(float DeltaTime)
{
	for (int i = 0; i < EntityiesInRunTime.size(); i++)
	{
		try
		{
			EntityiesInRunTime[i]->Update(DeltaTime);

			for (int o = 0; o < EntityiesInRunTime[i]->MyComponents.size(); o++)
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

		if (Y - OffsetY > 0 && RenderContent.size() - 1 < Y - OffsetY)
		{
			if (X - OffsetX > 0 && RenderContent[Y].length() < X - OffsetX)
			{
				if (RenderContent[Y - OffsetY][X - OffsetX] != ' ' && Importance >= CurrentImportance)
				{
					CurrentImportance = Importance;
					CurrentlyGoingToPush = RenderContent[Y - OffsetY];
					CurrentRenderingModifyer = EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer;
				}
			}
		}
	}

	string NewToPush = CurrentRenderingModifyer.PreRender();
	if (NewToPush != "NULL") { CurrentlyGoingToPush = NewToPush[0]; }

	cout << CurrentlyGoingToPush;
	if (NewLineAfter == true) { cout << endl; }

	CurrentRenderingModifyer.PostRender();
}

