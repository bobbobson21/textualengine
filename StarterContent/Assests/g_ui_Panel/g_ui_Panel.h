#pragma once

#include "../g_ui_Base/g_ui_Base.h"

class g_ui_Panel : virtual public g_ui_Base //use this to UI elements
{
protected:
	string BorderCharter = "x";
	string InsideCharter = " ";

	virtual void Update(float DeltaTime) override;
	void OnKeyValueSet(string Key, string Value) override;

private:
	void UpdateRender();
};

