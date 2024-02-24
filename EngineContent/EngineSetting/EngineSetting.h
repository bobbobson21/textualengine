#pragma once

#include "../BaseEntity/BaseEntity.h"
#include "../../GameContent/ConsoleReciver/ConsoleReciver.h"

namespace EngineSettings
{
	static int MinmalUpdateDelayInMircoSeconds = 2; //min delay between things like movement
	static int MinmalRenderDelayInMircoSeconds = 10; //max delay between frames
	static int Xcharizals = 50; //pixles across
	static int Ycharizals = 25; //pixles down
	static BaseEntity CommandConsoleCMD = (BaseEntity)ConsoleReciver(); //the console
	static int ConsoleAllowed = true;
}