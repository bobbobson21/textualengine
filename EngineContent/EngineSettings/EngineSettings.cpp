#include "EngineSettings.h"
#define EngineSettingsRunTimeSet(VAR,X) if (VAR == #X) {EngineSettings::Setting::X = Value; return true;} //to make my life a little easy
#define EngineSettingsGet(VAR,X) if (VAR == #X) {return EngineSettings::Setting::X; }


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
		EngineSettingsGet(Var, MinmalUpdateDelayInMircoSeconds);
		EngineSettingsGet(Var, MinmalRenderDelayInMircoSeconds);
		EngineSettingsGet(Var, RenderOffsetX);
		EngineSettingsGet(Var, RenderOffsetY);
		EngineSettingsGet(Var, VoidRenderColor);

		return INT_INVALID;
	}

	bool EngineSettings::GetUpToDateValue(string Var, bool TYPEID)
	{
		EngineSettingsGet(Var, ConsoleAllowed);

		return false;
	}

	int EngineSettings::GetConstValue(string Var, int TYPEID)
	{
		EngineSettingsGet(Var, XCharizals);
		EngineSettingsGet(Var, YCharizals);

		return INT_INVALID;
	}

	BaseEntity *EngineSettings::GetConstValue(string Var, BaseEntity TYPEID)
	{
		EngineSettingsGet(Var, CommandConsoleCMD);

		return (BaseEntity*) nullptr;
	}

