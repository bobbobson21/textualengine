#pragma once

#include "../../../EngineContent/BaseEntity/BaseEntity.h"

class g_ui_Base : virtual public BaseEntity //use this to UI elements
{
protected:
	float AnchorX = 0;
	float AnchorY = 0;

	float AnchorDirectionX = 0;
	float AnchorDirectionY = 0;

	float AnchorSizeX = 0;
	float AnchorSizeY = 0;

	void Update(float DeltaTime) override;
	void OnKeyValueSet(string Key, string Value) override;

public:
	void MatainScreenAttachment(); //put this in update to make UI move with screen
};

