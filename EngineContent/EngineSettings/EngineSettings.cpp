#include "EngineSettings.h"
#define EngineSettingsRunTimeSet(VAR,X) if (VAR == #X) {EngineSettings::X = Value; return true;} //to make my life a little easy
#define EngineSettingsRunTimeGet(VAR,X) if (VAR == #X) {return EngineSettings::X; }


	bool EngineSettings::ChangeInRunTime(string Var, int Value) //so setting can be chaged in runtime because you cant change static namespace values unless in namespace
	{
		EngineSettingsRunTimeSet(Var, MinmalUpdateDelayInMircoSeconds);
		EngineSettingsRunTimeSet(Var, MinmalRenderDelayInMircoSeconds);
		EngineSettingsRunTimeSet(Var, RenderOffsetX);
		EngineSettingsRunTimeSet(Var, RenderOffsetY);
		EngineSettingsRunTimeSet(Var, VoidRenderColor);

		return false; //if true is returned change was sucessful if not change was unsucessful
	}


	bool EngineSettings::ChangeInRunTime(string Var, bool Value) //theye also have to be static values as well
	{
		EngineSettingsRunTimeSet(Var, ConsoleAllowed);

		return false;
	}


	int EngineSettings::GetUpToDateValue(string Var, int TYPEID)
	{
		EngineSettingsRunTimeGet(Var, MinmalUpdateDelayInMircoSeconds);
		EngineSettingsRunTimeGet(Var, MinmalRenderDelayInMircoSeconds);
		EngineSettingsRunTimeGet(Var, RenderOffsetX);
		EngineSettingsRunTimeGet(Var, RenderOffsetY);
		EngineSettingsRunTimeGet(Var, VoidRenderColor);

		return INT_INVALID;
	}

	bool EngineSettings::GetUpToDateValue(string Var, bool TYPEID)
	{
		EngineSettingsRunTimeGet(Var, ConsoleAllowed);
	}

