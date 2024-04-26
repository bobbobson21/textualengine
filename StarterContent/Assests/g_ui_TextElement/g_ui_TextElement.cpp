#include "g_ui_TextElement.h"

void g_ui_TextElement::Update(float DeltaTime)
{
	MatainScreenAttachment();
}

void g_ui_TextElement::OnKeyValueSet(string Key, string Value)
{
	OnKeyValueSetBase(Key, Value);
}

void g_ui_TextElement::SetTextOnLine(string Text, int Line)
{
	MyRenderingInfo.ContentsToRender.resize((int)AnchorSizeY);

	if (Line >= 0 && Line < MyRenderingInfo.ContentsToRender.size())
	{
		MyRenderingInfo.ContentsToRender[Line] = Text;
	}
}

void g_ui_TextElement::SetTextAuto(string Text)
{
	vector<string> AutoTextData = vector<string>();

	while (Text.size() > 0)
	{
		string CurrentLine = Text.substr(0, AnchorSizeX);
		int LastSpacePos = CurrentLine.find_last_of(" ");
		CurrentLine = CurrentLine.substr(0, LastSpacePos - 1);

		AutoTextData.push_back(CurrentLine);
		Text = Text.substr(LastSpacePos + 1, Text.size() + (LastSpacePos));
	}

	MyRenderingInfo.ContentsToRender = AutoTextData;
}