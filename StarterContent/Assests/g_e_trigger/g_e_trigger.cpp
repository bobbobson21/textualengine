#include "g_e_trigger.h"

vector<BaseEntity*> g_e_trigger::TestTriggerOn;
int g_e_trigger::TriggerCount;

void g_e_trigger::Start()
{
	Identifyer = "Trigger";
	MyUniqueIndexInCount = TriggerCount;
	TriggerCount++;
}

void g_e_trigger::Update(float DeltaTime)
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
						TestTriggerOn[i]->SetKeyValue("TRIGInsideTrigger", to_string(MyUniqueIndexInCount));
						FireOut("OnTriggerEntered");
					}
				}
				else if (TestTriggerOn[i]->GetValueOfKey("TRIGInsideTrigger") == to_string(MyUniqueIndexInCount))
				{
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

void g_e_trigger::OnKeyValueSet(string Key, string Value)
{
	if (Key == "PosX")
	{
		try
		{
			MyOffsetX = stoi(Value);
		}
		catch(...) {};
	}

	if (Key == "PosY")
	{
		try
		{
			MyOffsetY = stoi(Value);
		}
		catch (...) {};
	}

	if (Key == "SizeX")
	{
		try
		{
			MySizeX = stoi(Value);
		}
		catch (...) {};
	}

	if (Key == "SizeY")
	{
		try
		{
			MySizeY = stoi(Value);
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
			FireOut("OnDisable");
		}
	}
}

void g_e_trigger::ReceiveFireInstruction(string Message, string Value)
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

bool g_e_trigger::IsOverlaping(int X, int Y, int SX, int SY)
{
	if (X <= MyOffsetX +MySizeX && MyOffsetX <= X +SX && Y <= MyOffsetY +MySizeY && MyOffsetY <= Y +SY )
	{
		return true;
	}
	return false;
}

void g_e_trigger::AllowEntToInterractWithTriggers(BaseEntity* Ent)
{
	TestTriggerOn.push_back(Ent);
}


