#include "RenderingModifier.h"

string RenderingModifier::PreRender(int X, int Y, string RenderingFor)
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
