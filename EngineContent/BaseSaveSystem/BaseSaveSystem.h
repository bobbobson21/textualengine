#pragma once

#include <String>
#include <fstream>

#include "../Marcos/Marcos.h"
#include "../BaseSaveObject/BaseSaveObject.h"

using namespace std;

class BaseSaveSystem
{
private:
	static string LocationOfLastSave;
	static string LocationOfLastLoad;
	static int ErrorCode;
public:

	static string GetLocationOfLastSave();
	static string GetLocationOfLastLoad();
	static int GetLastErrorCode();

	template <typename T>
	static void SaveDataToFile(string FileDir, T SaveObject)
	{
		try
		{
			dynamic_cast<BaseSaveObject>(SaveObject);
		}
		catch (...) { ErrorCode = -1; return; } //object is not a save based object it is likly we shouldnt save it

		fstream File(FileDir, std::ios::binary);

		if (File.good() == false)
		{
			ErrorCode = -2;
			return;
		}

		File.write(reinterpret_cast<char*>(&SaveObject), sizeof(SaveObject));
		File.close();

		ErrorCode = 1;
		LocationOfLastSave = FileDir;
	}

	template <typename T>
	static T& LoadDataFromFile(string FileDir, T LoadObject)
	{
		T Object = T();

		try
		{
			dynamic_cast<BaseSaveObject>(LoadObject);
		}
		catch (...) { ErrorCode = -1; return Object; } //object is not a save based object it is likly we shouldnt save it

		ifstream  File(FileDir, std::ios::binary);

		if (File.good() == false)
		{
			ErrorCode = -2;
			return;
		}

		File.read(reinterpret_cast<char*>(&Object), sizeof(LoadObject));
		File.close();

		ErrorCode = 1;
		LocationOfLastLoad = FileDir;

		return Object;
	}
};
