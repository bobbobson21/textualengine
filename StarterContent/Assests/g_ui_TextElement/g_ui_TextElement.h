#pragma once

#include "../g_ui_Base/g_ui_Base.h"

class g_ui_TextElement : virtual public g_ui_Base //use this to UI elements
{
protected:
	virtual void Update(float DeltaTime) override;
	virtual void OnKeyValueSet(string Key, string Value) override;

public:
	void SetTextOnLine(string Text, int Line);
	void SetTextAuto(string Text);
};

