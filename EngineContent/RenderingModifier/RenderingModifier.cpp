#include "RenderingModifier.h"

string RenderingModifier::PreRender()
{
	if (ColorOveride != -1)
	{
		HANDLE conout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(conout, ColorOveride);
	}

	return "NULL";
}

void RenderingModifier::PostRender()
{
}
