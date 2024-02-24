#pragma once

#include "../../EngineContent/BaseEntity/BaseEntity.h"

class ConsoleReciver : virtual public BaseEntity //this is in game content because we expect you to add your own commands but we dont expect you to mess with the engine content 
{//unless it is to change settings
	void ReceiveFireInstruction(string Message, string Value) override;

};

