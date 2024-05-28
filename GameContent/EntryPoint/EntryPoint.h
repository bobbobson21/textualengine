#pragma once

#include <windows.h>

#include "../../EngineContent/EngineSettings/EngineSettings.h"
#include "../../EngineContent/BaseEntity/BaseEntity.h"
#include "../../EngineContent/Audio/AudioBeepControl.h"
#include "../../EngineContent/BaseLevelSystem/BaseLevelSystem.h"

#include "../../StarterContent/Assests/g_e_Collider/g_e_Collider.h"
#include "../../StarterContent/Assests/g_e_Player/g_e_Player.h"
#include "../../StarterContent/Assests/g_e_Trigger/g_e_Trigger.h"
#include "../../StarterContent/Assests/g_e_WorldLayer/g_e_WorldLayer.h"

#include "../../StarterContent/Assests/g_m_WorldMaterial/g_m_WorldMat.h"
#include "../../StarterContent/Assests/g_m_playermat/g_m_PlayerMat.h"

using namespace std;

static int GameMain()
{
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_Collider);
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_Player);
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_Trigger);
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_WorldLayer);

	BaseLevelSystem::RegisterMaterialData ObtainMaterialDataFrom(g_m_WorldMat);
	BaseLevelSystem::RegisterMaterialData ObtainMaterialDataFrom(g_m_PlayerMat);

	TCHAR buffer[600] = { 0 };
	GetModuleFileName(NULL, buffer, 600); //puts our current file path in the buffer
	wstring FinishedPathWide = std::wstring(buffer).substr(0, std::wstring(buffer).find_last_of(L"\\/")); //resizes path to not include exer details
	string FinishedPath(FinishedPathWide.begin(), FinishedPathWide.end()); //converts path to useable format

	BaseLevelSystem::LoadLevel(FinishedPath +"\\BuildContent\\Levels\\TestLevel.dat");

	return 0;
}