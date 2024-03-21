#include "BaseEntity.h"

vector<BaseEntity *> BaseEntity::EntityiesInRunTime;
HANDLE BaseEntity::ConOut = GetStdHandle(STD_OUTPUT_HANDLE);

void BaseEntity::ReceiveFireInstruction(string Message, string Value)
{
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


void BaseEntity::OnKeyValueSet(string Key, string Value)
{
}

void BaseEntity::SetKeyValue(string Key, string Value, bool Hidden) //only works inside of the class defanition
{
	KeyValueList[Key] = Value;
	if (Hidden == false)
	{
		for (int i = 0; i < MyComponents.size(); i++)
		{
			try
			{
				MyComponents[i]->OnKeyValueSet(Key, Value); //sends message to ent components
			}
			catch (...) {}
		}

		OnKeyValueSet(Key, Value);
	}
}


void BaseEntity::Fire(string Message, string Value) 
{
	ReceiveFireInstruction(Message, Value); //sends message to ent

	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			MyComponents[i]->ReceiveFireInstruction(Message, Value); //sends message to ent components
		}
		catch (...) {}
	}
}

void BaseEntity::FireOut(string Condition)
{
	if (FireOuts.count(Condition) > 0)
	{
		for (int i = 0; i < FireOuts[Condition].size(); i++)
		{
			try
			{
				if (FireOuts[Condition][i].Ent != nullptr)
				{
					FireOuts[Condition][i].Ent->Fire(FireOuts[Condition][i].Message, FireOuts[Condition][i].Value);
				}
			}
			catch (...) {}
		}
	}
}

void BaseEntity::AddFireOut(BaseEntity* FireOutTo, string Condition, string Message, string Value) //sends message to ent if a condition is rasied
{
	if (FireOuts.count(Condition) > 0)
	{
		FireOuts[Condition].push_back(BaseEntity_FireOutInfo{FireOutTo,Message,Value});
	}
	else
	{
		FireOuts[Condition] = vector<BaseEntity_FireOutInfo>{ BaseEntity_FireOutInfo{FireOutTo,Message,Value} };
	}
}

void BaseEntity::RemoveAllFireOut()
{
	FireOuts.clear();
}

void BaseEntity::RemoveAllFireOutByEnt(BaseEntity* FireOutTo, string Condition)
{
	if (FireOuts.count(Condition) > 0) //condition is valid
	{
		for (int i = 0; i < FireOuts[Condition].size(); i++)
		{
			try
			{
				if (FireOuts[Condition][i].Ent == FireOutTo) //found our ent
				{
					FireOuts[Condition].erase(FireOuts[Condition].begin() + i); //removes fire
					i--;
				}
			}
			catch (...) {}
		}
	}
}

void BaseEntity::RemoveAllFireOutByEnt(BaseEntity* FireOutTo)
{
	for (std::map<string, vector<BaseEntity_FireOutInfo>>::iterator i = FireOuts.begin(); i != FireOuts.end(); ++i) //gose thougth evey condition
	{
		try
		{
			for (int o = 0; o < i->second.size(); o++) //gose thougth all fire outs for a given condition
			{
				try
				{
					if (i->second[o].Ent == FireOutTo) //found our ent
					{
						i->second.erase(i->second.begin() + o); //removes fire
						o--;
					}
				}
				catch (...) {}
			}
		}
		catch (...) {}
	}
}

void BaseEntity::RemoveAllFireOutByID(string Identifyer, string Condition)
{
	if (FireOuts.count(Condition) > 0) //condition is valid
	{
		for (int i = 0; i < FireOuts[Condition].size(); i++)
		{
			try
			{
				if (FireOuts[Condition][i].Ent->GetIdentifyer() == Identifyer) //found our ent by id
				{
					FireOuts[Condition].erase(FireOuts[Condition].begin() + i); //removes fire
					i--;
				}
			}
			catch (...) {}
		}
	}
}

void BaseEntity::RemoveAllFireOutByID(string Identifyer)
{
	for (std::map<string, vector<BaseEntity_FireOutInfo>>::iterator i = FireOuts.begin(); i != FireOuts.end(); ++i) //gose thougth evey condition
	{
		try
		{
			for (int o = 0; o < i->second.size(); o++) //gose thougth all fire outs for a given condition
			{
				try
				{
					if (i->second[o].Ent->GetIdentifyer() == Identifyer) //found our ent
					{
						i->second.erase(i->second.begin() + o); //removes fire
						o--;
					}
				}
				catch (...) {}
			}
		}
		catch (...) {}
	}
}


void BaseEntity::SetKeyValue(string Key, string Value) //sets key value but cant be hidden
{
	KeyValueList[Key] = Value;

	for (int i = 0; i < MyComponents.size(); i++)
	{
		try
		{
			MyComponents[i]->OnKeyValueSet(Key, Value); //sends message to ent components
		}
		catch (...) {}
	}

	OnKeyValueSet(Key, Value);
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

				INVALIDATE_DELETE(Ent->MyComponents[i]);
				Ent->MyComponents.erase(Ent->MyComponents.begin() + i); //destoy
				i--;
			}
		}
		catch (...) {}
	}

	Ent->MyComponents.shrink_to_fit();
}


void BaseEntity::Spawn(BaseEntity* Ent) //puts entity in run time
{
	EntityiesInRunTime.push_back(Ent);
	Ent->Start();
}

void BaseEntity::Remove(BaseEntity* Ent) //removes a given entity from the game
{
	Ent->OnRemove();

	for (int i = 0; i < Ent->MyComponents.size(); i++)
	{
		Ent->MyComponents[i]->OnRemove(); //tels entities componets it will be removed soon
		try
		{
			INVALIDATE_DELETE(Ent->MyComponents[i]);
			Ent->MyComponents.erase(Ent->MyComponents.begin() + i); //removes the components
		}
		catch (...) {}
	}

	Ent->MyComponents.shrink_to_fit(); //just encase momory isnt being auto removed on ent destruction

	for (int i = 0; i < EntityiesInRunTime.size(); i++) 
	{
		try
		{
			if (EntityiesInRunTime[i] == Ent) //finds ent spawned version
			{
				if (RenderingModifier::IsValid( EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer ) == true)
				{
					INVALIDATE_DELETE(EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer);
				}

				INVALIDATE_DELETE(EntityiesInRunTime[i]);
				EntityiesInRunTime.erase(EntityiesInRunTime.begin() + i); //destroys ent
				i--;
				return;
			}
		}
		catch (...) {}
	}

	EntityiesInRunTime.shrink_to_fit();
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
							INVALIDATE_DELETE(EntityiesInRunTime[i]->MyComponents[o]);
							EntityiesInRunTime[i]->MyComponents.erase(EntityiesInRunTime[i]->MyComponents.begin() + o); //dose destruction
						}
						catch (...) {}
					}
				}

				EntityiesInRunTime[i]->MyComponents.shrink_to_fit(); //just encase

				try
				{
					if (RenderingModifier::IsValid(EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer) == true)
					{
						delete EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer;
						EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer = nullptr;
					}

					INVALIDATE_DELETE(EntityiesInRunTime[i]);
					EntityiesInRunTime.erase(EntityiesInRunTime.begin() + i);//destroys ent
					i--;
				}
				catch (...) {}
			}
		}
		catch(...) {}
	}

	EntityiesInRunTime.shrink_to_fit();
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
							INVALIDATE_DELETE(EntityiesInRunTime[i]->MyComponents[o]);
							EntityiesInRunTime[i]->MyComponents.erase(EntityiesInRunTime[i]->MyComponents.begin() + o); //dose destruction
						}
						catch (...) {}
					}
				}

				EntityiesInRunTime[i]->MyComponents.shrink_to_fit(); //just encase

				try
				{
					if (RenderingModifier::IsValid(EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer) == true)
					{
						INVALIDATE_DELETE(EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer);
					}

					INVALIDATE_DELETE(EntityiesInRunTime[i]);
					EntityiesInRunTime.erase(EntityiesInRunTime.begin() + i); //destroys ent
					i--;
				}
				catch (...) {}
			}
		}
		catch (...) {}
	}

	EntityiesInRunTime.shrink_to_fit();
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

vector<BaseEntity*> BaseEntity::GetEntitiesByKeyValue(string Key, string Value)
{
	vector<BaseEntity*> Ents = vector<BaseEntity*>();

	for (int i = 0; i < EntityiesInRunTime.size(); i++)
	{
		try
		{
			if (EntityiesInRunTime[i] != nullptr && EntityiesInRunTime[i]->GetValueOfKey(Key) == Value)
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
				try
				{
					if (EntityiesInRunTime[i] == Ent)
					{
						return true;
					}
				}
				catch (...) {}
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


void BaseEntity::ProcessRendering(int X, int Y, bool NewLineAfter, RenderingModifier* PostProcessing) //https://www.youtube.com/results?search_query=ansi+c%2B%2B
{
	int RendededCharizalImportance = 0;
	string RendededCharizalToPush = " ";
	RenderingModifier* RendededCharizalRenderingModifyer = nullptr;
	bool RendededBlockPostProcessing = false;

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

				if (Y - CurrentOffsetY >= 0 && Y - CurrentOffsetY < CurrentRenderContent.size()) //is with in screenbounds y
				{
					if (X - CurrentOffsetX >= 0 && X - CurrentOffsetX < CurrentRenderContent[Y - CurrentOffsetY].length()) //is with in screenbounds x
					{
						char CurrentCharizal = CurrentRenderContent[Y - CurrentOffsetY][X - CurrentOffsetX];

						if (CurrentCharizal != ' ' && CurrentImportance >= RendededCharizalImportance) //is not an enpty pixle and is a pixle of higher importance
						{
							RendededCharizalImportance = CurrentImportance; //sets the pixle data to the curent pixle to render
							RendededCharizalToPush = CurrentCharizal;
							RendededCharizalRenderingModifyer = EntityiesInRunTime[i]->MyRenderingInfo.MyModifyer;
							RendededBlockPostProcessing = EntityiesInRunTime[i]->MyRenderingInfo.PostProcessingProof;
						}
					}
				}
			}
		}
		catch (...) {}
	}

	string OldRendededCharizalToPush = RendededCharizalToPush; //this is for the post processer
	if (RenderingModifier::IsValid(RendededCharizalRenderingModifyer) == true)
	{
		string NewToPush = RendededCharizalRenderingModifyer->PreRender(X, Y, RendededCharizalToPush, STR_NULL); //runs the render modifyer that can be used to create stuff like flashing materials
		SetConsoleTextAttribute(ConOut, RendededCharizalRenderingModifyer->GetReturnAttribute());

		if (NewToPush != STR_NULL) { RendededCharizalToPush = NewToPush[0]; }

		if (RendededBlockPostProcessing != true && RenderingModifier::IsValid(PostProcessing) == true) //post processing for mat
		{
			string NewToPush = PostProcessing->PreRender(X, Y, RendededCharizalToPush, OldRendededCharizalToPush);
			SetConsoleTextAttribute(ConOut, PostProcessing->GetReturnAttribute());

			if (NewToPush != STR_NULL) { RendededCharizalToPush = NewToPush[0]; }
		}
	}

		//cout << RendededCharizalToPush;
		//if (NewLineAfter == true) { cout << endl; }

	fwrite(RendededCharizalToPush.c_str(), 1, 1, stdout);
	if (NewLineAfter == true) { fwrite("\n", 1, 2, stdout); }
	

	if (RenderingModifier::IsValid(RendededCharizalRenderingModifyer) == true)
	{
		RendededCharizalRenderingModifyer->PostRender();

		if (RendededBlockPostProcessing != true && RenderingModifier::IsValid(PostProcessing) == true) //post processing
		{
			PostProcessing->PostRender();
		}
	}
}
