#pragma once

#include <String>
#include <windows.h>
#include <Vector>

#include "../Marcos/Marcos.h"

using namespace std;

class RenderingModifier
{
private:
	int Attribute;
	static int OldAttribute;
	static vector<int> ScreenCord;

protected:
	void SetReturnAttribute(int Att);

public:
	virtual ~RenderingModifier() {}

	static bool IsValid(RenderingModifier* Material);

	static int GetOldReturnAttribute();
	int GetReturnAttribute();

	static void SetScreenCord(int X, int Y);
	static vector<int> GetScreenCord();

	virtual void SetRenderingModifierData(string Key, string Value);
	virtual string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor);
	virtual void PostRender();
};

