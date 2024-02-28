#pragma once

#include "ConsoleReciver.h"
#include "../../EngineContent/EngineSettings/EngineSettings.h"

void ConsoleReciver::ReceiveFireInstruction(string Message, string Value)
{
	if (Message == "KillTask" && Value == "1")
	{
		exit(0);
	}

	if (Message == "SetRenderingOffsetX")
	{
		try
		{
			EngineSettings::ChangeInRunTime( "RenderOffsetX", stoi(Value) );
		}
		catch (...) {}
	}


	if (Message == "SetRenderingOffsetY")
	{
		try
		{
			EngineSettings::ChangeInRunTime("RenderOffsetY", stoi(Value));
		}
		catch (...) {}
	}

}