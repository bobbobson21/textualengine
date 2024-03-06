#include "g_ec_MotionCollider.h"

void g_ec_MotionCollider::Start()
{
	Identifyer = "g_ec_MotionCollider";
}

void g_ec_MotionCollider::OnKeyValueSet(string Key, string Value)
{
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
}

void g_ec_MotionCollider::ReceiveFireInstruction(string Message, string Value)
{
	if (Message == "Enable")
	{
		SelfOwner->SetKeyValue("C_MC_Enabled", "1");
	}

	if (Message == "Disable")
	{
		SelfOwner->SetKeyValue("C_MC_Enabled", "0");
	}
}

bool g_ec_MotionCollider::DoCollisionCheck(int X, int Y)
{
	if (SelfOwner->GetValueOfKey("C_MC_Enabled") != "0")
	{
		string Layers = SelfOwner->GetValueOfKey("C_MC_IngoreLayers");
		if (Layers == STR_NULL) { Layers = "NULL_COLLISION"; }

		return g_e_Collider::IsOverlapingAnyCollider(X, Y,MySizeX,MySizeY, Layers);
	}
}
