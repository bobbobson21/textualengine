#pragma once

#include "../BaseEntity/BaseEntity.h"
#include "../../GameContent/ConsoleReciver/ConsoleReciver.h"

namespace EngineSettings
{
	static int MinmalUpdateDelayInMircoSeconds = 500; //min delay between things like movement
	static int MinmalRenderDelayInMircoSeconds = 500; //max delay between frames

	static int XCharizals = 100; //pixles across
	static int YCharizals = 25; //pixles down

	static int RenderOffsetX = 0; //rendering offset
	static int RenderOffsetY = 0;

	static BaseEntity *CommandConsoleCMD = new ConsoleReciver(); //the console
	static bool ConsoleAllowed = true;
}