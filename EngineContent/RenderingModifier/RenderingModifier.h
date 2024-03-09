#pragma once

#include <String>
#include <windows.h>

#include "../Marcos/Marcos.h"

using namespace std;

class RenderingModifier
{
private:
	int Attribute;
	static int OldAttribute;

protected:
	void SetReturnAttribute(int Att);

public:
	virtual ~RenderingModifier() {}

	static bool IsValid(RenderingModifier* Material);

	static int GetOldReturnAttribute();
	int GetReturnAttribute();
	virtual string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor);
	virtual void PostRender();
};

