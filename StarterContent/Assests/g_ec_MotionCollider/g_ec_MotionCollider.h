#pragma once

#include "../../../EngineContent/BaseComponent/BaseComponent.h"
#include "../g_e_Collider/g_e_Collider.h"

class g_ec_MotionCollider : virtual public BaseComponent //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings

private:
	float MySizeX;
	float MySizeY;

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
	bool DoCollisionCheck(float X, float Y);
	bool Move(float DeltaTime);//returend value = if it was sucessful at moving the object
};

