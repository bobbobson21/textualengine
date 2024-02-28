#include "EngineSettings.h"

	bool EngineSettings::ChangeInRunTime(string Var, int Value) //so setting can be chaged in runtime because you cant change static namespace values unless in namespace
	{
		if (Var == "MinmalUpdateDelayInMircoSeconds")
		{
			EngineSettings::MinmalUpdateDelayInMircoSeconds = Value;
			return true;
		}

		if (Var == "MinmalRenderDelayInMircoSeconds")
		{
			EngineSettings::MinmalRenderDelayInMircoSeconds = Value;
			return true;
		}

		if (Var == "RenderOffsetX")
		{
			EngineSettings::RenderOffsetX = Value;
			return true;
		}

		if (Var == "RenderOffsetY")
		{
			EngineSettings::RenderOffsetY = Value;
			return true;
		}

		if (Var == "VoidRenderColor")
		{
			EngineSettings::VoidRenderColor = Value;
			return true;
		}
		return false; //if true is returned change was sucessful if not change was unsucessful
	}


	bool EngineSettings::ChangeInRunTime(string Var, bool Value) //theye also have to be static values as well
	{
		if (Var == "ConsoleAllowed")
		{
			EngineSettings::ConsoleAllowed = Value;
			return true;
		}

		return false;
	}


	int EngineSettings::GetUpToDateValue(string Var, int TYPEID)
	{
		if (Var == "MinmalUpdateDelayInMircoSeconds")
		{
			return EngineSettings::MinmalUpdateDelayInMircoSeconds;
		}

		if (Var == "MinmalRenderDelayInMircoSeconds")
		{
			return EngineSettings::MinmalRenderDelayInMircoSeconds;
		}

		if (Var == "RenderOffsetX")
		{
			return EngineSettings::RenderOffsetX;
		}

		if (Var == "RenderOffsetY")
		{
			return EngineSettings::RenderOffsetY;
		}

		if (Var == "VoidRenderColor")
		{
			return EngineSettings::VoidRenderColor;
		}
		return INT_INVALID;
	}

	bool EngineSettings::GetUpToDateValue(string Var, bool TYPEID)
	{
		if (Var == "ConsoleAllowed")
		{
			return EngineSettings::ConsoleAllowed;
		}
	}

