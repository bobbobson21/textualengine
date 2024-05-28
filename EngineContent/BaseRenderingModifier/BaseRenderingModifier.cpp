#include "BaseRenderingModifier.h"

int BaseRenderingModifier::OldAttribute;
vector<int> BaseRenderingModifier::ScreenCord;

void BaseRenderingModifier::SetReturnAttribute(int Att)
{
	OldAttribute = Att;
	Attribute = Att;
}

bool BaseRenderingModifier::IsValid(BaseRenderingModifier* Material)
{
	return (Material != nullptr);
}

int BaseRenderingModifier::GetOldReturnAttribute()
{
	return OldAttribute;
}

int BaseRenderingModifier::GetReturnAttribute()
{
	return Attribute;
}

void BaseRenderingModifier::SetScreenCord(int X, int Y)
{
	ScreenCord.resize(2);

	ScreenCord[0] = X;
	ScreenCord[1] = Y;
}

vector<int> BaseRenderingModifier::GetScreenCord()
{
	return ScreenCord;
}

void BaseRenderingModifier::SetBaseRenderingModifierData(string Key, string Value)
{
}

string BaseRenderingModifier::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	return STR_NULL;
}

void BaseRenderingModifier::PostRender()
{
}
