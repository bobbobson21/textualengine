﻿#pragma once

#include "../../EngineContent/EngineSettings/EngineSettings.h"
#include "../../EngineContent/BaseEntity/BaseEntity.h"
#include "../../EngineContent/Audio/AudioBeepControl.h"

#include "../../StarterContent/Assests/g_e_Player/g_e_Player.h"
#include "../../StarterContent/Assests/g_e_WorldLayer/g_e_WorldLayer.h"
#include "../../StarterContent/Assests/g_e_Collider/g_e_Collider.h"

#include "../../StarterContent/Assests/g_m_WorldMaterial/g_m_WorldMat.h"

static int GameMain()
{
	g_e_WorldLayer *Grass = new g_e_WorldLayer();
	BaseEntity::Spawn(Grass);

	BaseEntity_RenderingInfo GrassRenderContent = BaseEntity_RenderingInfo();
	GrassRenderContent.MyModifyer = new g_m_WorldMat();
	GrassRenderContent.ContentsToRender.resize(27);
	GrassRenderContent.ContentsToRender[0] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[1] = "GGGGGGGG|||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[2] = "GGGGG|||||||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[3] = "GGG||||||||||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[4] = "GGG||||||||||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[5] = "GGG||||||||||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[6] = "GGG||||||||||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[7] = "GGG||||||||||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[8] = "GGG||||||||||||||||||||GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[9] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[10] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[11] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[12] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[13] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[14] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[15] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[16] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[17] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[18] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[19] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[20] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[21] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[22] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[23] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[24] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[25] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	GrassRenderContent.ContentsToRender[26] = "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";

	Grass->SetRenderContents(GrassRenderContent);;

	g_e_Player *Player = new g_e_Player();
	BaseEntity::Spawn(Player);
	Player->SetKeyValue("PosX", "10");
	Player->SetKeyValue("PosY", "10");

	g_e_Collider* ColliderA = new g_e_Collider();
	BaseEntity::Spawn(ColliderA);
	ColliderA->SetKeyValue("PosX", "2");
	ColliderA->SetKeyValue("PosY", "3");
	ColliderA->SetKeyValue("SizeX", "20");
	ColliderA->SetKeyValue("SizeY", "5");

	g_e_Collider* ColliderB = new g_e_Collider();
	BaseEntity::Spawn(ColliderB);
	ColliderB->SetKeyValue("PosX", "4");
	ColliderB->SetKeyValue("PosY", "2");
	ColliderB->SetKeyValue("SizeX", "17");
	ColliderB->SetKeyValue("SizeY", "1");

	g_e_Collider* ColliderC = new g_e_Collider();
	BaseEntity::Spawn(ColliderC);
	ColliderC->SetKeyValue("PosX", "7");
	ColliderC->SetKeyValue("PosY", "1");
	ColliderC->SetKeyValue("SizeX", "13");
	ColliderC->SetKeyValue("SizeY", "1");

	return 0;
}