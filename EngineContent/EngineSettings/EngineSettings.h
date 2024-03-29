#pragma once

#include "../BaseEntity/BaseEntity.h"
#include "../../StarterContent/ConsoleReciver/ConsoleReciver.h"
#include "../../StarterContent/Assests/g_m_GenericPostProcessingMat/g_m_GenericPostProcessingMat.h"

#include <String>

class BaseEntity;

namespace EngineSettings
{
	namespace Setting //set default settings in here
	{
		static int MinmalUpdateDelayInMilliSeconds = 20; //min delay between things like movement
		static int MinmalRenderDelayInMilliSeconds = 20; //max delay between frames

		static const int XCharizals = 55; //pixles across
		static const int YCharizals = 20; //pixles down

		static const int SaveObjectSize = 80;

		static int RenderOffsetX = 0; //rendering offset
		static int RenderOffsetY = 0;
		static int VoidRenderColor = 7; //the color of nothing
		static RenderingModifier* PostPorcessingShader = nullptr; //new g_m_GenericPostProcessingMat();

		static BaseEntity* CommandConsoleCMD = new ConsoleReciver(); //the console //PS this is an entity because they can store stuff othere ents and components may want to access in KV formating but this ent is also never validated meaning it has to be destroy manually
		static bool ConsoleAllowed = true; //technically CommandConsoleCMD is not const but technically it cant change during run time
	}

	bool ChangeInRunTime(string Var, int Value); //do note not all values should be updated dureing runtime so not all values are
	bool ChangeInRunTime(string Var, bool Value);
	bool ChangeInRunTime(string Var, RenderingModifier *RenderingModifier);

	int GetUpToDateValue(string Var, int TYPEID);
	bool GetUpToDateValue(string Var, bool TYPEID);
	RenderingModifier *GetUpToDateValue(string Var, RenderingModifier TYPEID);

	int GetConstValue(string Var, int TYPEID); //these vauses can not be changed in run time 
	BaseEntity *GetConstValue(string Var, BaseEntity TYPEID);
}