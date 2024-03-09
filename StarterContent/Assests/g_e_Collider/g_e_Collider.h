#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"

class g_e_Collider : virtual public BaseEntity //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings
private:
	int MyOffsetX;
	int MyOffsetY;
	int MySizeX;
	int MySizeY;

	static vector<g_e_Collider *> StaticColliderList;

protected:
	void Start() override;
	void OnRemove() override;
	void OnKeyValueSet(string Key, string Value) override;

public:
	void ReceiveFireInstruction(string Message, string Value) override;
	bool IsOverlaping(int X, int Y, int SX, int SY);
	
	static bool IsOverlapingAnyCollider(int X, int Y, int SX, int SY, string IngoreLayers);
};

