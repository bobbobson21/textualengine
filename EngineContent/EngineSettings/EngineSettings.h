#pragma once

#include "../BaseEntity/BaseEntity.h"
#include "../../StarterContent/ConsoleReciver/ConsoleReciver.h"

class BaseEntity;

namespace EngineSettings
{
	static int MinmalUpdateDelayInMircoSeconds = 100; //min delay between things like movement
	static int MinmalRenderDelayInMircoSeconds = 100; //max delay between frames

	static int XCharizals = 100; //pixles across
	static int YCharizals = 25; //pixles down

	static int RenderOffsetX = 0; //rendering offset
	static int RenderOffsetY = 0;
	static int VoidRenderColor = 7; //the color of nothing

	static BaseEntity *CommandConsoleCMD = new ConsoleReciver(); //the console
	static bool ConsoleAllowed = true;
}