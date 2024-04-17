#pragma once

#include "../g_ui_Base/g_ui_Base.h"

class g_ui_Panel : virtual public g_ui_Base //use this to UI elements
{
private:
	void UpdateRender();

protected:
	virtual void Update(float DeltaTime) override;
	virtual void OnKeyValueSet(string Key, string Value) override;

public:
	string BorderCharter = "x";
	string InsideCharter = " ";
};

