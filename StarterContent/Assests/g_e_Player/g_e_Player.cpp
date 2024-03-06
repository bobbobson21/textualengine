#include "g_e_Player.h"

void g_e_Player::Start()
{
	MyRenderingInfo.Importance = 4;
	MyRenderingInfo.ContentsToRender.push_back("@@");
	MyRenderingInfo.ContentsToRender.push_back("@@");
	MyRenderingInfo.ContentsToRender.push_back("##");
	MyRenderingInfo.MyModifyer = new g_m_PlayerMat();
	SetKeyValue("Health", "100");
	SetKeyValue("SizeX", "2");
	SetKeyValue("SizeY", "2");

	BaseEntity::AddComponent( this, Collider );
}

void g_e_Player::OnKeyValueSet(string Key, string Value)
{
	if (Key == "PosX")
	{
		try
		{
			MyRenderingInfo.OffsetX = stoi(Value);
			EngineSettings::ChangeInRunTime("RenderOffsetX", (MyRenderingInfo.OffsetX - (EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)) / 2)) + 1);
		}
		catch(...) {};
	}

	if (Key == "PosY")
	{
		try
		{
			MyRenderingInfo.OffsetY = stoi(Value);
			EngineSettings::ChangeInRunTime("RenderOffsetY", (MyRenderingInfo.OffsetY - (EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)) / 2)) + 1);
		}
		catch (...) {};
	}

}

void g_e_Player::Update(float DeltaTime)
{
	if (GetAsyncKeyState(VK_UP))
	{
		int Temp = 0;
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX, MyRenderingInfo.OffsetY +2 - 1) == false) { Temp = 1; } //player close to wall
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX, MyRenderingInfo.OffsetY +2 - 2) == false) { Temp = 2; } //player can move freely
		if (Temp == 0) { return; } //player is tring to move thougth wall

		MyRenderingInfo.OffsetY -= Temp;
		SetKeyValue("PosY", to_string(MyRenderingInfo.OffsetY), true); //the true makes it so OnKeyValueSet dosent run
		EngineSettings::ChangeInRunTime("RenderOffsetY", (MyRenderingInfo.OffsetY - (EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)) / 2)) + 1); //moves camera
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		int Temp = 0;
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX, MyRenderingInfo.OffsetY + 2 + 1) == false) { Temp = 1; }
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX, MyRenderingInfo.OffsetY + 2 + 2) == false) { Temp = 2; }
		if (Temp == 0) { return; }

		MyRenderingInfo.OffsetY += Temp;
		SetKeyValue("PosY", to_string(MyRenderingInfo.OffsetY), true);
		EngineSettings::ChangeInRunTime("RenderOffsetY", (MyRenderingInfo.OffsetY - (EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)) / 2)) + 1);
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		int Temp = 0;
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX -1, MyRenderingInfo.OffsetY + 2) == false) { Temp = 1; }
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX -2, MyRenderingInfo.OffsetY + 2) == false) { Temp = 2; }
		if (Temp == 0) { return; }

		MyRenderingInfo.OffsetX -= Temp;
		SetKeyValue("PosX", to_string(MyRenderingInfo.OffsetX), true);
		EngineSettings::ChangeInRunTime("RenderOffsetX", (MyRenderingInfo.OffsetX - (EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)) / 2)) + 1);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		int Temp = 0;
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX + 1, MyRenderingInfo.OffsetY + 2) == false) { Temp = 1; }
		if (Collider->DoCollisionCheck(MyRenderingInfo.OffsetX + 2, MyRenderingInfo.OffsetY + 2) == false) { Temp = 2; }
		if (Temp == 0) { return; }

		MyRenderingInfo.OffsetX += 2;
		SetKeyValue("PosX", to_string(MyRenderingInfo.OffsetX), true);
		EngineSettings::ChangeInRunTime("RenderOffsetX", (MyRenderingInfo.OffsetX - (EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)) / 2)) + 1);
	}
}
