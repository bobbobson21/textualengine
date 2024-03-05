#include "RenderingModifier.h"

bool RenderingModifier::IsValid(RenderingModifier* Material)
{
	return (Material != nullptr);
}

string RenderingModifier::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	if (ColorOveride != -1)
	{
		SetConsoleTextAttribute(OutHandle, ColorOveride);
	}

	return STR_NULL;
}

void RenderingModifier::PostRender()
{
}
