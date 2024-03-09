#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"

class g_e_trigger : virtual public BaseEntity //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings
private:
	int MyOffsetX;
	int MyOffsetY;
	int MySizeX;
	int MySizeY;

	static int TriggerCount;
	int MyUniqueIndexInCount;

	static vector<BaseEntity*> TestTriggerOn;

protected:
	void Start() override;
	void Update(float DeltaTime) override;
	void OnKeyValueSet(string Key, string Value) override;
	void ReceiveFireInstruction(string Message, string Value) override;

public:
	bool IsOverlaping(int X, int Y, int SX, int SY);
	static void AllowEntToInterractWithTriggers(BaseEntity* Ent); //this entity can overlap with triggers

};

