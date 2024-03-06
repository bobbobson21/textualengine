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

	if (Key == "C_MC_Enabled")
	{
		if (Value == "0")
		{
			SelfOwner->FireOut("OnColliderDisable");
		}
		else
		{
			SelfOwner->FireOut("OnColliderEnable");
		}
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
		if (Layers == STR_NULL) { Layers = "VOID_COLLISION"; } //this way if collider are set to null and the layer to ingore is set to null the layer dosent get ingored because thats bad since null id the default

		return g_e_Collider::IsOverlapingAnyCollider(X, Y,MySizeX,MySizeY, Layers);
	}
	return false;
}
