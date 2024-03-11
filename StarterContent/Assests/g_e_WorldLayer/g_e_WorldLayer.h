#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"
#include "../../../EngineContent/EngineSettings/EngineSettings.h"

class g_e_WorldLayer : virtual public BaseEntity //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings

public:
	void Start() override;
	void SetRenderContents(BaseEntity_RenderingInfo Rend);
};

