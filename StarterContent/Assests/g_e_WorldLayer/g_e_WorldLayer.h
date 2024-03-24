#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"
#include "../../../EngineContent/BaseLevelSystem/BaseLevelSystem.h"

class g_e_WorldLayer : virtual public BaseEntity //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings
protected:
	void Start() override;
	void ReceiveFireInstruction(string Message, string Value) override;

public:
	void SetRenderContents(BaseEntity_RenderingInfo Rend);

};

