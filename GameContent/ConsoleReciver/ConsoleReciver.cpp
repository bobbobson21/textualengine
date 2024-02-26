#pragma once

#include "ConsoleReciver.h"
#include "../../EngineContent/EngineSettings/EngineSettings.h"

void ConsoleReciver::ReceiveFireInstruction(string Message, string Value)
{
	if (Message == "TEST" && Value == "1")
	{
		exit(0);
	}

	if (Message == "SetRenderingOffsetX")
	{
		try
		{
			EngineSettings::RenderOffsetX = stoi(Value);
		}
		catch (...) {}
	}


	if (Message == "SetRenderingOffsetX")
	{
		try
		{
			EngineSettings::RenderOffsetY = stoi(Value);
		}
		catch (...) {}
	}

}