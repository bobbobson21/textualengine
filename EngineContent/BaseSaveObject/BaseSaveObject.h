#pragma once

#include <String>

#include "../Marcos/Marcos.h"
#include "../EngineSettings/EngineSettings.h"

using namespace std;

class BaseSaveObject
{
private:
	bool BoolArray[EngineSettings::Setting::SaveObjectSize];
	int IntArray[EngineSettings::Setting::SaveObjectSize];
	float FloatArray[EngineSettings::Setting::SaveObjectSize];
	char CharArray[EngineSettings::Setting::SaveObjectSize];
	string StringArray[EngineSettings::Setting::SaveObjectSize];

public:
	bool GetBool(unsigned int Index);
	int GetInt(unsigned int Index);
	float GetFloat(unsigned int Index);
	char GetChar(unsigned int Index);
	string GetString(unsigned int Index);

	bool SetBool(unsigned int Index, bool Value);
	bool SetInt(unsigned int Index, int Value);
	bool SetFloat(unsigned int Index, float Value);
	bool SetChar(unsigned int Index, char Value);
	bool SetString(unsigned int Index, string Value);

};