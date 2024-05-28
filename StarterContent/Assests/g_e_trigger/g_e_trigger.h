#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"

class g_e_Trigger : virtual public BaseEntity //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings
private:
	static int TriggerCount;
	int MyUniqueIndexInCount;

	static vector<BaseEntity*> TestTriggerOn;

protected:
	Vector2D<int> MyOffset;
	Vector2D<int> MySize;

	void TriggerStart();
	void TriggerUpdate();
	void TriggerOnKeyValueSet(string Key, string Value);
	void TriggerReceiveFireInstruction(string Message, string Value);

	virtual void Start() override;
	virtual void Update(float DeltaTime) override;
	virtual void OnKeyValueSet(string Key, string Value) override;
	virtual void ReceiveFireInstruction(string Message, string Value) override;


	virtual void OnTriggerInterraction(BaseEntity* Ent, bool TrueIfEnteringFalseIfLeaving);

public:
	bool IsOverlaping(int X, int Y, int SX, int SY); //should only be int so it is accuarte with visuals
	static void AllowEntToInterractWithTriggers(BaseEntity* Ent); //this entity can overlap with triggers

};

