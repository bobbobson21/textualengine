#include "g_e_Player.h"

void g_e_Player::Start()
{
	Identifyer = "PlayerCharter";

	Collider = new g_ec_MotionCollider();
	BaseEntity::AddComponent(this, Collider);

	MyRenderingInfo.Importance = 4;
	MyRenderingInfo.ContentsToRender.push_back("@@");
	MyRenderingInfo.ContentsToRender.push_back("@@");
	MyRenderingInfo.ContentsToRender.push_back("##");
	MyRenderingInfo.MyModifyer = new g_m_PlayerMat();

	SetKeyValue("MotionColliderMoveDirAmount", "2");
	SetKeyValue("Health", "100");

	SetKeyValue("SizeX", "2");
	SetKeyValue("SizeY", "1");

	SetKeyValue("SizeOffsetX", "0");
	SetKeyValue("SizeOffsetY", "2");
}

void g_e_Player::OnKeyValueSet(string Key, string Value)
{
	if (Key == "PosX")
	{
		try
		{
			MyRenderingInfo.OffsetX = (int)stof(Value);
			EngineSettings::ChangeInRunTime("RenderOffsetX", (MyRenderingInfo.OffsetX - (EngineSettings::GetConstValue("XCharizals", TYPE_REP(int) ) / 2)) + 1);
		}
		catch(...) {};
	}

	if (Key == "PosY")
	{
		try
		{
			MyRenderingInfo.OffsetY = (int)stof(Value);
			EngineSettings::ChangeInRunTime("RenderOffsetY", (MyRenderingInfo.OffsetY - (EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)) / 2)) + 1);
		}
		catch (...) {};
	}

}

void g_e_Player::Update(float DeltaTime)
{
	if (GetAsyncKeyState(VK_UP))
	{
		SetKeyValue("MotionColliderMoveDirX", "0");
		SetKeyValue("MotionColliderMoveDirY", "-1");
		Collider->Move();
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		SetKeyValue("MotionColliderMoveDirX", "0");
		SetKeyValue("MotionColliderMoveDirY", "1");
		Collider->Move();
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		SetKeyValue("MotionColliderMoveDirX", "-1");
		SetKeyValue("MotionColliderMoveDirY", "0");
		Collider->Move();
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		SetKeyValue("MotionColliderMoveDirX", "1");
		SetKeyValue("MotionColliderMoveDirY", "0");
		Collider->Move();
	}
}
