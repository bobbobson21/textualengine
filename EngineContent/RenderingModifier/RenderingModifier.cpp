#include "RenderingModifier.h"

int RenderingModifier::OldAttribute;
vector<int> RenderingModifier::ScreenCord;

void RenderingModifier::SetReturnAttribute(int Att)
{
	OldAttribute = Att;
	Attribute = Att;
}

bool RenderingModifier::IsValid(RenderingModifier* Material)
{
	return (Material != nullptr);
}

int RenderingModifier::GetOldReturnAttribute()
{
	return OldAttribute;
}

int RenderingModifier::GetReturnAttribute()
{
	return Attribute;
}

void RenderingModifier::SetScreenCord(int X, int Y)
{
	ScreenCord.resize(2);

	ScreenCord[0] = X;
	ScreenCord[1] = Y;
}

vector<int> RenderingModifier::GetScreenCord()
{
	return ScreenCord;
}

string RenderingModifier::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	return STR_NULL;
}

void RenderingModifier::PostRender()
{
}
