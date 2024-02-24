#include "ConsoleReciver.h"

void ConsoleReciver::ReceiveFireInstruction(string Message, string Value)
{
	if (Message == "TEST" && Value == "1")
	{
		exit(0);
	}
}
