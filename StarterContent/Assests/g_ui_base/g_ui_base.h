#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"

class g_ui_base : virtual public BaseEntity //use this to UI elements
{
	int AnchorX = 0;
	int AnchorY = 0;
	int AnchorOffsetX = 0;
	int AnchorOffsetY = 0;


	void Update(float DeltaTime) override;
	void MatainScreenAttachment(); //put this in update to make UI move with screen
};

