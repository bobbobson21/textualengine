#include "BaseEntity.h"

vector<BaseEntity *> BaseEntity::EntityiesInRunTime;

void BaseEntity::ReceiveFireInstruction(string Message, string Value)
{
}

void BaseEntity::FireOut(string Condition)
{
	if (KeyValueList.count(Condition) > 0)
	{
		

	}
}

string BaseEntity::GetIdentifyer()
{
	return Identifyer;
}

void BaseEntity::Update(float DeltaTime)
{
}

void BaseEntity::Start()
{
}

void BaseEntity::OnRemove()
{
}

void BaseEntity::Fire(string Message, string Value)
{
	ReceiveFireInstruction(Message, Value);

	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			MyComponents[i]->ReceiveFireInstruction(Message, Value);
		}
		catch (...) {}
	}
}

void BaseEntity::AddFireOut(BaseEntity* FireOutTo, string Condition, string Message, string Value)
{
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


void BaseEntity::AddComponent(BaseEntity* Ent, BaseComponent* Com)
{
	Com->SelfOwner = Ent; //so the component knows who its boss is
	Ent->MyComponents.push_back(Com);
	Com->Start();
}

vector<BaseComponent*> BaseEntity::GetComponents(BaseEntity* Ent, string Identifyer) //get component by identifyer
{
	vector<BaseComponent*> Components = vector<BaseComponent*>();

	for (int i = 0; i < Ent->MyComponents.size(); i++)
	{
		try
		{
			if (Ent->MyComponents[i] != nullptr &&  Ent->MyComponents[i]->GetIdentifyer() == Identifyer) //found what we are looking for
			{
				Components.push_back( Ent->MyComponents[i] ); //add it to returend items
			}
		}
		catch (...) {}
	}

	return Components;
}

void BaseEntity::RemoveAllComponentsOfID(BaseEntity* Ent, string Identifyer) //removes a component form an entity by its idenifyer
{
	for (int i = 0; i >= 0 && Ent->MyComponents.size() > 0 && i < Ent->MyComponents.size(); i++)
	{
		try
		{
			if (Ent->MyComponents[i] != nullptr && Ent->MyComponents[i]->GetIdentifyer() == Identifyer) //found what we are looking for
			{
				Ent->MyComponents[i]->OnRemove();

				delete Ent->MyComponents[i]; //DESTROY
				Ent->MyComponents.erase(Ent->MyComponents.begin() + i); //destoy
				i--;
			}
		}
		catch (...) {}
	}
}


void BaseEntity::Spawn(BaseEntity* Ent) //puts entity in run time
{
	EntityiesInRunTime.push_back(Ent);
	Ent->Start();
}

void BaseEntity::Remove(BaseEntity* Ent) //removes a given entity from the game
{
	for (int i = 0; i < Ent->MyComponents.size(); i++)
	{
		Ent->MyComponents[i]->OnRemove(); //tels entities componets it will be removed soon
		try
		{
			delete Ent->MyComponents[i];
			Ent->MyComponents.erase(Ent->MyComponents.begin() + i); //removes the components
		}
		catch (...) {}
	}

	Ent->OnRemove();

	for (int i = 0; i < EntityiesInRunTime.size(); i++) 
	{
		try
		{
			if (EntityiesInRunTime[i] == Ent) //finds ent spawned version
			{
				delete EntityiesInRunTime[i];
				EntityiesInRunTime.erase(EntityiesInRunTime.begin() + i); //destroys ent
				i--;
				return;
			}
		}
		catch (...) {}
	}
}

void BaseEntity::RemoveAll()
{
	for (int i = 0; i >= 0 && EntityiesInRunTime.size() > 0 && i < EntityiesInRunTime.size(); i++) //finds all entities and removes them
	{
		try
		{
			EntityiesInRunTime[i]->OnRemove();//tesl the ent your going to die now wahaha

			if (EntityiesInRunTime[i] != nullptr)
			{
				for (int o = 0; o < EntityiesInRunTime[i]->MyComponents.size(); o++) //destroys ents components
				{
					if (EntityiesInRunTime[i]->MyComponents[o] != nullptr)
					{
						EntityiesInRunTime[i]->MyComponents[o]->OnRemove(); //tells destruction
						try
						{
							delete EntityiesInRunTime[i]->MyComponents[o];
							EntityiesInRunTime[i]->MyComponents.erase(EntityiesInRunTime[i]->MyComponents.begin() + o); //dose destruction
						}
						catch (...) {}
					}
				}

				try
				{
					delete EntityiesInRunTime[i];
					EntityiesInRunTime.erase(EntityiesInRunTime.begin() + i);//destroys ent
					i--;
				}
				catch (...) {}
			}
		}
		catch(...) {}
	}
}

void BaseEntity::RemoveAllOfID(string Identifyer)
{
	for (int i = 0; i >= 0 && EntityiesInRunTime.size() > 0 && i < EntityiesInRunTime.size(); i++) //finds all entities and removes them
	{
		try
		{
			if (EntityiesInRunTime[i] != nullptr && EntityiesInRunTime[i]->GetIdentifyer() == Identifyer)
			{
				EntityiesInRunTime[i]->OnRemove(); //alert ent of there death

				for (int o = 0; o < EntityiesInRunTime[i]->MyComponents.size(); o++) //destroys ents components
				{
					if (EntityiesInRunTime[i]->MyComponents[o] != nullptr)
					{
						EntityiesInRunTime[i]->MyComponents[o]->OnRemove(); //tells comps they will be destroyed
						try
						{
							delete EntityiesInRunTime[i]->MyComponents[o];
							EntityiesInRunTime[i]->MyComponents.erase(EntityiesInRunTime[i]->MyComponents.begin() + o); //dose destruction
						}
						catch (...) {}
					}
				}

				try
				{
					delete EntityiesInRunTime[i];
					EntityiesInRunTime.erase(EntityiesInRunTime.begin() + i); //destroys ent
					i--;
				}
				catch (...) {}
			}
		}
		catch (...) {}
	}
}

vector<BaseEntity*> BaseEntity::GetEntities(string Identifyer)
{
	vector<BaseEntity*> Ents = vector<BaseEntity*>();

	for (int i = 0; i < EntityiesInRunTime.size(); i++)
	{
		try
		{
			if (EntityiesInRunTime[i] != nullptr && EntityiesInRunTime[i]->GetIdentifyer() == Identifyer)
			{
				Ents.push_back(EntityiesInRunTime[i]); //this ent == identifyer add it to return
			}
		}
		catch (...) {}

	}
	return Ents;
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
			if (EntityiesInRunTime[i] != nullptr)
			{
				EntityiesInRunTime[i]->Update(DeltaTime); //updates all entities

				for (int o = 0; o < EntityiesInRunTime[i]->MyComponents.size(); o++) //then updates there components
				{
					try
					{
						if (EntityiesInRunTime[i]->MyComponents[o] != nullptr)
						{
							EntityiesInRunTime[i]->MyComponents[o]->SelfOwner = EntityiesInRunTime[i];
							EntityiesInRunTime[i]->MyComponents[o]->Update(DeltaTime);
						}
					}
					catch (...) {}
				}
			}
		}
		catch (...) {}
	}
}

void BaseEntity::ProcessRendering(int X, int Y, bool NewLineAfter)
{
	int RendededCharizalImportance = 0;
	string RendededCharizalToPush = " ";
	RenderingModifier* RendededCharizalRenderingModifyer = nullptr;

	for (int i = 0; i < EntityiesInRunTime.size(); i++)
	{
		try
		{
			if (EntityiesInRunTime[i] != nullptr)
			{
				vector<string> CurrentRenderContent = EntityiesInRunTime[i]->MyRenderingInfo.ContentsToRender;
				int CurrentOffsetX = EntityiesInRunTime[i]->MyRenderingInfo.OffsetX;
				int CurrentOffsetY = EntityiesInRunTime[i]->MyRenderingInfo.OffsetY;
				int CurrentImportance = EntityiesInRunTime[i]->MyRenderingInfo.Importance;

				if (Y - CurrentOffsetY >= 0 && Y + CurrentOffsetY < CurrentRenderContent.size()) //is with in screenbounds y
				{
					if (X - CurrentOffsetX >= 0 && X + CurrentOffsetX < CurrentRenderContent[Y - CurrentOffsetY].length()) //is with in screenbounds x
					{
						char CurrentCharizal = CurrentRenderContent[Y - CurrentOffsetY][X - CurrentOffsetX];

						if (CurrentCharizal != ' ' && CurrentImportance >= RendededCharizalImportance) //is not an enpty pixle and is a pixle of higher importance
						{
							RendededCharizalImportance = CurrentImportance; //sets the pixle data to the curent pixle to render
							RendededCharizalToPush = CurrentCharizal;
							RendededCharizalRenderingModifyer = EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer;
						}
					}
				}
			}
		}
		catch (...) {}
	}

	if (RenderingModifier::IsValid(RendededCharizalRenderingModifyer) == true)
	{
		string NewToPush = RendededCharizalRenderingModifyer->PreRender(X, Y, RendededCharizalToPush); //runs the render modifyer that can be used to create stuff like flashing materials
		if (NewToPush != STR_NULL) { RendededCharizalToPush = NewToPush[0]; }
	}

	//cout << RendededCharizalToPush;
	//if (NewLineAfter == true) { cout << endl; }

	fwrite(RendededCharizalToPush.c_str(), 1, 1, stdout);
	if (NewLineAfter == true) { fwrite("\n", 1, 2, stdout); }

	if (RenderingModifier::IsValid(RendededCharizalRenderingModifyer) == true)
	{
		RendededCharizalRenderingModifyer->PostRender();
	}	
}

