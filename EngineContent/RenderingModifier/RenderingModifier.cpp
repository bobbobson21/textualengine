#include "RenderingModifier.h"

int RenderingModifier::OldAttribute;

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

string RenderingModifier::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	return STR_NULL;
}

void RenderingModifier::PostRender()
{
}
