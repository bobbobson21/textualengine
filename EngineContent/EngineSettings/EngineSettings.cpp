#include "EngineSettings.h"
#define EngineSettingsRunTimeSet(VAR,VAL,X) if (VAR == #X) {EngineSettings::Setting::X = VAL; return true;} //to make my life a little easy
#define EngineSettingsGet(VAR,X) if (VAR == #X) {return EngineSettings::Setting::X; }


	bool EngineSettings::ChangeInRunTime(string Var, int Value) //so setting can be chaged in runtime because you cant change static namespace values unless in namespace
	{
		EngineSettingsRunTimeSet(Var, Value, MinmalUpdateDelayInMilliSeconds);
		EngineSettingsRunTimeSet(Var, Value, MinmalRenderDelayInMilliSeconds);
		EngineSettingsRunTimeSet(Var, Value, RenderOffsetX);
		EngineSettingsRunTimeSet(Var, Value, RenderOffsetY);
		EngineSettingsRunTimeSet(Var, Value, VoidRenderColor);

		return false; //if true is returned change was sucessful if not change was unsucessful
	}

	bool EngineSettings::ChangeInRunTime(string Var, bool Value) //theye also have to be static values as well
	{
		EngineSettingsRunTimeSet(Var, Value, ConsoleAllowed);

		return false;
	}

	bool EngineSettings::ChangeInRunTime(string Var, BaseRenderingModifier *Value)
	{
		EngineSettingsRunTimeSet(Var, Value, PostPorcessingShader)

		return false;
	}


	int EngineSettings::GetUpToDateValue(string Var, int TYPEID)
	{
		EngineSettingsGet(Var, MinmalUpdateDelayInMilliSeconds);
		EngineSettingsGet(Var, MinmalRenderDelayInMilliSeconds);
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

	BaseRenderingModifier* EngineSettings::GetUpToDateValue(string Var, BaseRenderingModifier TYPEID)
	{
		EngineSettingsGet(Var, PostPorcessingShader);

		return (BaseRenderingModifier*) nullptr;
	}


	int EngineSettings::GetConstValue(string Var, int TYPEID)
	{
		EngineSettingsGet(Var, XCharizals);
		EngineSettingsGet(Var, YCharizals);
		EngineSettingsGet(Var, SaveObjectSize);

		return INT_INVALID;
	}

	BaseEntity *EngineSettings::GetConstValue(string Var, BaseEntity TYPEID)
	{
		EngineSettingsGet(Var, CommandConsoleCMD);

		return (BaseEntity*) nullptr;
	}

