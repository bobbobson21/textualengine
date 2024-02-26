#pragma once

#include <String>
#include <windows.h>

#include "../Marcos/Marcos.h"

using namespace std;

class RenderingModifier
{
public:
	int ColorOveride = -1;
	virtual string PreRender(int X, int Y);
	virtual void PostRender();
};

