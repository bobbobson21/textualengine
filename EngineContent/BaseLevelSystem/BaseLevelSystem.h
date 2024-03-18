#pragma once

#include <functional>
#include <String>
#include <Map>

#include "../BaseEntity/BaseEntity.h"

#define ObtainEntitySpawnDataFrom( X ) <X> (#X)
#define ObtainMaterialDataFrom( Y ) ObtainEntitySpawnDataFrom( Y )

using namespace std;

class BaseLevelSystem
{
private:
	static map<string, function<BaseEntity*()>> EntitySpawnDataStorage;
	static map<string, function<RenderingModifier* ()>> MaterialDataStorage;
	static BaseEntity_RenderingInfo RenderingDataDump;

	static string ImproveFormatting(string Input);

public:
	template<typename T>
	static void RegisterEntitySpawnData(string ClassId);

	template<typename T>
	static void RegisterMaterialData(string MaterialId);

	static BaseEntity *CreateNewEntity(string ClassId);
	static RenderingModifier* CreateNewMaterialInstance(string MaterialId);

	static BaseEntity_RenderingInfo CollectRenderingData();
	static void RequestEntityToCollectRendingData(BaseEntity* Ent);

	static void LoadLevel(vector<string> LevelAssest);
	static void UnLoadLevel();
};

