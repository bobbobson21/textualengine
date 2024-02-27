#pragma once

#include <String>
#include <windows.h>

#include "../Marcos/Marcos.h"

using namespace std;

class RenderingModifier
{
public:
	HANDLE OutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int ColorOveride = -1;

	static bool IsValid(RenderingModifier* Material);

	virtual string PreRender(int X, int Y, string RenderingFor);
	virtual void PostRender();
};

