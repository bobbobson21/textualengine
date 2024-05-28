#include "g_e_Trigger.h"

vector<BaseEntity*> g_e_Trigger::TestTriggerOn;
int g_e_Trigger::TriggerCount;

void g_e_Trigger::TriggerStart()
{
	Identifyer = "Trigger";
	MyUniqueIndexInCount = TriggerCount;
	TriggerCount++;
}

void g_e_Trigger::TriggerUpdate()
{
	if (GetValueOfKey("Enabled") != "0")
	{
		for (int i = 0; i < TestTriggerOn.size(); i++)
		{
			try
			{
				if (BaseEntity::IsVaild(TestTriggerOn[i]) == true)
				{
					if (IsOverlaping(stoi(TestTriggerOn[i]->GetValueOfKey("PosX")), stoi(TestTriggerOn[i]->GetValueOfKey("PosY")), stoi(TestTriggerOn[i]->GetValueOfKey("SizeX")), stoi(TestTriggerOn[i]->GetValueOfKey("SizeY"))) == true)
					{
						if (TestTriggerOn[i]->GetValueOfKey("TRIGInsideTrigger") != to_string(MyUniqueIndexInCount))
						{
							OnTriggerInterraction(TestTriggerOn[i], true);
							TestTriggerOn[i]->SetKeyValue("TRIGInsideTrigger", to_string(MyUniqueIndexInCount));
							FireOut("OnTriggerEntered");
						}
					}
					else if (TestTriggerOn[i]->GetValueOfKey("TRIGInsideTrigger") == to_string(MyUniqueIndexInCount))
					{
						OnTriggerInterraction(TestTriggerOn[i], false);
						TestTriggerOn[i]->SetKeyValue("TRIGInsideTrigger", STR_NULL);
						FireOut("OnTriggerExited");
					}
				}
				else
				{
					try
					{
						TestTriggerOn.erase(TestTriggerOn.begin() + i);
						i--;
					}
					catch (...) {}
				}
			}
			catch (...) {}
		}
	}
}

void g_e_Trigger::TriggerOnKeyValueSet(string Key, string Value)
{
	if (Key == "Pos")
	{
		if (Key.find(" ") != string::npos)
		{
			try
			{
				SetKeyValue("PosX", Key.substr(0, Key.find(" ") - 1));
				SetKeyValue("PosY", Key.substr(Key.find(" ") + 1, Key.size() - Key.find(" ")));
			}
			catch (...) {}
		}

	}

	if (Key == "PosX")
	{
		try
		{
			MyOffset.X = stoi(Value);
		}
		catch (...) {};
	}

	if (Key == "PosY")
	{
		try
		{
			MyOffset.Y = stoi(Value);
		}
		catch (...) {};
	}

	if (Key == "SizeX")
	{
		try
		{
			MySize.X = stoi(Value);
		}
		catch (...) {};
	}

	if (Key == "SizeY")
	{
		try
		{
			MySize.Y = stoi(Value);
		}
		catch (...) {};
	}

	if (Key == "Enabled")
	{
		if (Value == "0")
		{
			FireOut("OnDisable");
		}
		else
		{
			FireOut("OnEnabled");
		}
	}
}

void g_e_Trigger::TriggerReceiveFireInstruction(string Message, string Value)
{
	if (Message == "Enable")
	{
		SetKeyValue("Enabled", "1");
	}

	if (Message == "Disable")
	{
		SetKeyValue("Enabled", "0");
	}
}


void g_e_Trigger::Start()
{
	TriggerStart();
}

void g_e_Trigger::Update(float DeltaTime)
{
	TriggerUpdate();
}

void g_e_Trigger::OnKeyValueSet(string Key, string Value)
{
	TriggerOnKeyValueSet(Key, Value);
}

void g_e_Trigger::ReceiveFireInstruction(string Message, string Value)
{
	TriggerReceiveFireInstruction(Message, Value);
}


void g_e_Trigger::OnTriggerInterraction(BaseEntity* Ent, bool TrueIfEnteringFalseIfLeaving)
{
}


bool g_e_Trigger::IsOverlaping(int X, int Y, int SX, int SY)
{
	if (X <= MyOffset.X +MySize.X && MyOffset.X <= X +SX && Y <= MyOffset.Y +MySize.Y && MyOffset.Y <= Y +SY )
	{
		return true;
	}
	return false;
}

void g_e_Trigger::AllowEntToInterractWithTriggers(BaseEntity* Ent)
{
	TestTriggerOn.push_back(Ent);
}


