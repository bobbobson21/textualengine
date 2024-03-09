#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"
#include "../../../EngineContent/BaseComponent/BaseComponent.h"
#include "../../../EngineContent/EngineSettings/EngineSettings.h"

#include "../g_m_playermat/g_m_PlayerMat.h"
#include "../g_ec_MotionCollider/g_ec_MotionCollider.h"

class g_e_Player : virtual public BaseEntity //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings

private:
	g_ec_MotionCollider* Collider = nullptr;

protected:
	void Start() override;
	void Update(float DeltaTime) override;
	void OnKeyValueSet(string Key, string Value) override;

};

