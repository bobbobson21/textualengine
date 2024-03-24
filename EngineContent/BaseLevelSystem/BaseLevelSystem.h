#pragma once

#include <functional>
#include <iostream>
#include <String>
#include <Map>

#include <fstream>

#include "../BaseEntity/BaseEntity.h"

#define ObtainEntitySpawnDataFrom( X ) (#X,[](){return new X();})
#define ObtainMaterialDataFrom( Y ) ObtainEntitySpawnDataFrom( Y )

using namespace std;

class BaseLevelSystem
{
private:
	static map<string, function<BaseEntity*()>> EntitySpawnDataStorage;
	static map<string, function<RenderingModifier* ()>> MaterialDataStorage;
	static BaseEntity_RenderingInfo RenderingDataDump;

	static string ImproveFormatting(string Input);
	static vector<string> ExtractViaComma(string Input); //DO THIS AT HOME

public:
	static void RegisterEntitySpawnData(string ClassId, function<BaseEntity* ()> Function);
	static void RegisterMaterialData(string MaterialId, function<RenderingModifier* ()> Function);

	static BaseEntity *CreateNewEntity(string ClassId);
	static RenderingModifier* CreateNewMaterialInstance(string MaterialId);

	static BaseEntity_RenderingInfo CollectRenderingData();
	static void RequestEntityToCollectRendingData(BaseEntity* Ent);

	static void LoadLevel(string PathToAssest);
	static void LoadLevel(vector<string> LevelAssestAsVector);
	static void UnLoadLevel();
};

