#pragma once

#include <String>
#include <windows.h>

using namespace std;

class RenderingModifier
{
public:
	int ColorOveride = -1;
	virtual string PreRender();
	virtual void PostRender();
};

