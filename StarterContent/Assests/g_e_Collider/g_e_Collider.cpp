#include "g_e_Collider.h"

vector<g_e_Collider*> g_e_Collider::StaticColliderList;

void g_e_Collider::Start()
{
	Identifyer = "StaticCollider";
	StaticColliderList.push_back(this);
}

void g_e_Collider::OnRemove()
{
	for (int i = 0; i < StaticColliderList.size(); i++)
	{
		try
		{
			if (StaticColliderList[i] == this)
			{
				StaticColliderList.erase(StaticColliderList.begin() + i);
				i--;
			}
		}
		catch (...) {}
	}
}

void g_e_Collider::OnKeyValueSet(string Key, string Value)
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

void g_e_Collider::ReceiveFireInstruction(string Message, string Value)
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

bool g_e_Collider::IsOverlaping(int X, int Y, int SX, int SY)
{
	if (X <= MyOffsetX + MySizeX && MyOffsetX <= X + SX && Y <= MyOffsetY + MySizeY && MyOffsetY <= Y + SY)
	{
		return true;
	}
	return false;
}

bool g_e_Collider::IsOverlaping(float X, float Y, float SX, float SY)
{
	if (X <= MyOffsetX + MySizeX && MyOffsetX <= X + SX && Y <= MyOffsetY + MySizeY && MyOffsetY <= Y + SY)
	{
		return true;
	}
	return false;
}


bool g_e_Collider::IsOverlapingAnyCollider(int X, int Y, int SX, int SY, string IngoreLayers)
{
	for (int i = 0; i < StaticColliderList.size(); i++)
	{
		try
		{
			if (StaticColliderList[i] != nullptr && StaticColliderList[i]->IsOverlaping(X, Y, SX, SY) == true)
			{
				string ToFind = StaticColliderList[i]->GetValueOfKey("Layer").c_str();
				if (IngoreLayers.find(ToFind) == string::npos && StaticColliderList[i]->GetValueOfKey("Enabled") != "0")
				{
					return true;
				}
			}
		}
		catch (...) {}
	}
	return false;
}

bool g_e_Collider::IsOverlapingAnyCollider(float X, float Y, float SX, float SY, string IngoreLayers)
{
	for (int i = 0; i < StaticColliderList.size(); i++)
	{
		try
		{
			if (StaticColliderList[i] != nullptr && StaticColliderList[i]->IsOverlaping(X, Y, SX, SY) == true)
			{
				string ToFind = StaticColliderList[i]->GetValueOfKey("Layer").c_str();
				if (IngoreLayers.find(ToFind) == string::npos && StaticColliderList[i]->GetValueOfKey("Enabled") != "0")
				{
					return true;
				}
			}
		}
		catch (...) {}
	}
	return false;
}

