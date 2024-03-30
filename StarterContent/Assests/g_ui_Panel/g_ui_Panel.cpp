#include "g_ui_Panel.h"

void g_ui_Panel::Update(float DeltaTime)
{
	MatainScreenAttachment();
	UpdateRender();
}

void g_ui_Panel::OnKeyValueSet(string Key, string Value)
{
	g_ui_Base::OnKeyValueSet(Key, Value);

	
}

void g_ui_Panel::UpdateRender()
{
	string LineToRender = "";
	for (int i = 0; i <= AnchorSizeX; i++) { LineToRender += BorderCharter; } //Creates the lines for the top and bottom part of the box

	string GapToRender = "";
	GapToRender += BorderCharter;
	for (int i = 0; i <= AnchorSizeX -2; i++) { LineToRender += InsideCharter; } //Creates the lines for the top and bottom part of the box
	GapToRender += BorderCharter;

	MyRenderingInfo.ContentsToRender.resize(AnchorSizeY);

	for (int i = 0; i < AnchorSizeY; i++)
	{
		if (i == 0 || i == AnchorSizeY - 1)
		{
			MyRenderingInfo.ContentsToRender[i] = LineToRender;
		}
		else
		{
			MyRenderingInfo.ContentsToRender[i] = GapToRender;
		}
	}

}
