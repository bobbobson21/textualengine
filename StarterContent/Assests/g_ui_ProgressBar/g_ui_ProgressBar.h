#pragma once

#include "../g_ui_Base/g_ui_Base.h"

class g_ui_ProgressBar : virtual public g_ui_Base //use this to UI elements
{
protected:
	bool DisplayPercent = false;
	float Percentage = 0;
	string ProgressCharter = "|";
	string NoProgressCharter = ".";

	virtual void Update(float DeltaTime) override;
	void OnKeyValueSet(string Key, string Value) override;

private:
	void UpdateRender();
};

