#pragma once

#include "../../EngineContent/EngineSettings/EngineSettings.h"
#include "../../EngineContent/BaseEntity/BaseEntity.h"
#include "../../EngineContent/Audio/AudioBeepControl.h"
#include "../../EngineContent/BaseLevelSystem/BaseLevelSystem.h"

#include "../../StarterContent/Assests/g_e_Collider/g_e_Collider.h"
#include "../../StarterContent/Assests/g_e_Player/g_e_Player.h"
#include "../../StarterContent/Assests/g_e_trigger/g_e_trigger.h"
#include "../../StarterContent/Assests/g_e_WorldLayer/g_e_WorldLayer.h"

#include "../../StarterContent/Assests/g_m_WorldMaterial/g_m_WorldMat.h"
#include "../../StarterContent/Assests/g_m_playermat/g_m_PlayerMat.h"


static int GameMain()
{
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_Collider);
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_Player);
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_trigger);
	BaseLevelSystem::RegisterEntitySpawnData ObtainEntitySpawnDataFrom(g_e_WorldLayer);

	BaseLevelSystem::RegisterMaterialData ObtainMaterialDataFrom(g_m_WorldMat);
	BaseLevelSystem::RegisterMaterialData ObtainMaterialDataFrom(g_m_PlayerMat);

	BaseLevelSystem::LoadLevel("C:\\Users\\dsbkh\\OneDrive\\Desktop\\github projects\\textualengine\\StarterContent\\levels\\TestLevel.dat");

	return 0;
}