#pragma once

#include "ConsoleReciver.h"
#include "../../EngineContent/EngineSettings/EngineSettings.h"

#include "../Assests/g_m_GenericPostProcessingMat/g_m_GenericPostProcessingMat.h"

void ConsoleReciver::ReceiveFireInstruction(string Message, string Value)
{
	if (Message == "System")
	{
		system(Value.c_str());
	}

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

	if (Message == "KillAllEnts" && Value == "1")
	{
		BaseEntity::RemoveAll();
	}

	if (Message == "KillAllEntsOfType")
	{
		BaseEntity::RemoveAllOfID( Value );
	}

	if (Message == "SetPostProcessingEffect")
	{
		if (RenderingModifier::IsValid(EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(RenderingModifier))) == true) //gets rid of old post processing effect
		{
			delete EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(RenderingModifier));
		}

		if (Value == "GPPM")
		{
			EngineSettings::ChangeInRunTime("PostPorcessingShader", new g_m_GenericPostProcessingMat());
		}// make more ppe command values using this secion of code as an example bellow
	}
}