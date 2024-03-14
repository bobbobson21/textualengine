#pragma once

#include "../../../EngineContent/BaseComponent/BaseComponent.h"
#include "../g_e_Collider/g_e_Collider.h"

class g_ec_MotionCollider : virtual public BaseComponent //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings

private:
	int MySizeX;
	int MySizeY;

	int MySizeOffsetX;
	int MySizeOffsetY;

	int MoveX;
	int MoveY;
	int MoveAmount;

protected:
	void Start() override;
	void OnKeyValueSet(string Key, string Value) override;
	void ReceiveFireInstruction(string Message, string Value) override;

public:
	bool DoCollisionCheck(int X, int Y);
	bool Move();//returend value = if it was sucessful at moving the object
};

