#include "RenderingModifier.h"

string RenderingModifier::PreRender(int X, int Y)
{
	if (ColorOveride != -1)
	{
		HANDLE conout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(conout, ColorOveride);
	}

	return STR_NULL;
}

void RenderingModifier::PostRender()
{
}
