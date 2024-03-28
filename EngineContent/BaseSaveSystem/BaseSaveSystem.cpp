#include "BaseSaveSystem.h"

string BaseSaveSystem::LocationOfLastSave;
string BaseSaveSystem::LocationOfLastLoad;
int BaseSaveSystem::ErrorCode;

string BaseSaveSystem::GetLocationOfLastSave()
{
	return LocationOfLastSave;
}

string BaseSaveSystem::GetLocationOfLastLoad()
{
	return LocationOfLastLoad;
}

int BaseSaveSystem::GetLastErrorCode()
{
	return ErrorCode;
}
