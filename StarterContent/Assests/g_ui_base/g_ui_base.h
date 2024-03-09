#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"

class g_ui_base : virtual public BaseEntity //use this to UI elements
{
protected:
	int AnchorX = 0;
	int AnchorY = 0;

	int AnchorOffsetX = 0;
	int AnchorOffsetY = 0;

	int AnchorOffsetMulX = 0;
	int AnchorOffsetMulY = 0;

	void Update(float DeltaTime) override;

public:
	void MatainScreenAttachment(); //put this in update to make UI move with screen
};

