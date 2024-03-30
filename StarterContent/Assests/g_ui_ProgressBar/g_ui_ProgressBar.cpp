#include "g_ui_ProgressBar.h"

void g_ui_ProgressBar::Update(float DeltaTime)
{
	MatainScreenAttachment();
	UpdateRender();
}

void g_ui_ProgressBar::OnKeyValueSet(string Key, string Value)
{
	g_ui_Base::OnKeyValueSet(Key, Value);

	if (Key == "Percentage")
	{
		try
		{
			Percentage = stof(Value);
		}
		catch (...) {};
	}

	if (Key == "DisplayPercent")
	{
		try
		{
			DisplayPercent = (Value == "1");
		}
		catch (...) {};
	}

	if (Key == "ProgressCharter")
	{
		try
		{
			ProgressCharter = Value[0];
		}
		catch (...) {};
	}

	if (Key == "NoProgressCharter")
	{
		try
		{
			NoProgressCharter = Value[0];
		}
		catch (...) {};
	}
}

void g_ui_ProgressBar::UpdateRender()
{
	string ProgressBarSmall = "";
	int TempAnchorSizeX = (int)AnchorSizeX;
	bool CanRenderPercent = false;

	if (TempAnchorSizeX > 5 && DisplayPercent == true)
	{
		CanRenderPercent = true;
		TempAnchorSizeX -= 5;
	}

	for (int X = 0; X < TempAnchorSizeX; X++)
	{
		if (X <= ((float)Percentage * TempAnchorSizeX))
		{
			ProgressBarSmall += ProgressCharter;
		}
		else
		{
			ProgressBarSmall += NoProgressCharter;
		}
	}

	if (CanRenderPercent == true)
	{
		string PercentZeros = "";
		int PercentAmount = (int)((float)Percentage * 100.f);
		PercentAmount = min(max(PercentAmount, 0), 999);

		if (PercentAmount < 100) { PercentZeros += "0"; }
		if (PercentAmount < 10) { PercentZeros += "0"; }
		ProgressBarSmall += " %" + PercentZeros + to_string(PercentAmount);
	}

	MyRenderingInfo.ContentsToRender.resize((int)AnchorSizeY);
	for (int Y = 0; Y < (int)AnchorSizeY; Y++)
	{
		MyRenderingInfo.ContentsToRender[Y] = ProgressBarSmall;
	}
}
