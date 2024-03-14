#include "g_ec_MotionCollider.h"

void g_ec_MotionCollider::Start()
{
	Identifyer = "MotionCollider_Component";
}

void g_ec_MotionCollider::OnKeyValueSet(string Key, string Value)
{
	if (Key == "SizeX")
	{
		try
		{
			MySizeX = (int)stof(Value);
		}
		catch (...) {};
	}

	if (Key == "SizeY")
	{
		try
		{
			MySizeY = (int)stof(Value);
		}
		catch (...) {};
	}

	if (Key == "MotionColliderMoveDirX")
	{
		try
		{
			MoveX = stof(Value);
		}
		catch (...) {};
	}

	if (Key == "MotionColliderMoveDirY")
	{
		try
		{
			MoveY = stof(Value);
		}
		catch (...) {};
	}

	if (Key == "SizeOffsetX")
	{
		try
		{
			MySizeOffsetX = stof(Value);
		}
		catch (...) {};
	}

	if (Key == "SizeOffsetY")
	{
		try
		{
			MySizeOffsetY = stof(Value);
		}
		catch (...) {};
	}

	if (Key == "MotionColliderMoveDirAmount") //basically this is speed
	{
		try
		{
			MoveAmount = stof(Value);
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
	if (Message == "MotionColliderEnable")
	{
		SelfOwner->SetKeyValue("C_MC_Enabled", "1");
	}

	if (Message == "MotionColliderDisable")
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

bool g_ec_MotionCollider::Move()
{
	try
	{
		float PosX = stof(SelfOwner->GetValueOfKey("PosX"));
		float PosY = stof(SelfOwner->GetValueOfKey("PosY"));
		int CurrentMoveAmount = MoveAmount;

		while (CurrentMoveAmount >= 0)
		{
			if (g_ec_MotionCollider::DoCollisionCheck(PosX + MySizeOffsetX + (MoveX * CurrentMoveAmount), PosY + MySizeOffsetY + (MoveY * CurrentMoveAmount)) == false)
			{
				SelfOwner->SetKeyValue("PosX", to_string(PosX + (MoveX * CurrentMoveAmount)));
				SelfOwner->SetKeyValue("PosY", to_string(PosY + (MoveY * CurrentMoveAmount)));
				break;
			}
			CurrentMoveAmount--;
		}

		return true;
	}
	catch (...) 
	{
		return false;
	}
}
