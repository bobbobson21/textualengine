#pragma once

#include <String>
#include <windows.h>
#include <Vector>

#include "../Marcos/Marcos.h"

using namespace std;

class BaseRenderingModifier
{
private:
	int Attribute;
	static int OldAttribute;
	static vector<int> ScreenCord;

protected:
	void SetReturnAttribute(int Att);

public:
	virtual ~BaseRenderingModifier() {}

	static bool IsValid(BaseRenderingModifier* Material);

	static int GetOldReturnAttribute();
	int GetReturnAttribute();

	static void SetScreenCord(int X, int Y);
	static vector<int> GetScreenCord();

	virtual void SetBaseRenderingModifierData(string Key, string Value);
	virtual string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor);
	virtual void PostRender();
};

