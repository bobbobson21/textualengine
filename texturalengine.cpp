// teXturalengine.cpp : This file contains the 'main' function. Program eXecution begins and ends there.
//

#include <iostream>
#include <Thread>
#include <Vector>
#include <chrono>
#include <Windows.h>

#include "EngineContent/EngineSetting/EngineSetting.h"
#include "EngineContent/BaseEntity/BaseEntity.h"
#include "EngineContent/Audio/AudioBeepControl.h"

#include "GameContent/EntryPoint/EntryPoint.h"

using namespace std;

void ThreadUpdateLoop()
{
	float LastDeltaTime = 0;

	while (true)
	{
		auto start = chrono::high_resolution_clock::now(); //delta time start

		BaseEntity::ProcessUpdate(LastDeltaTime); //updates all entities
		Sleep(EngineSettings::MinmalUpdateDelayInMircoSeconds);

		auto end = chrono::high_resolution_clock::now(); //delta time end
		LastDeltaTime = (float)(end - start).count(); //calulate delta time
	}
}

void ThreadRenderLoop()
{
	while (true)
	{
		for (int y = 0; y <= EngineSettings::Ycharizals; y++) //renders all the charizals on the Y
		{
			for (int x = 0; x <= EngineSettings::Xcharizals; x++) //renders a line of charizals
			{
				BaseEntity::ProcessRendering(x,y,(x == EngineSettings::Xcharizals) );
			}

		}
		Sleep(EngineSettings::MinmalRenderDelayInMircoSeconds);
		system("cls"); //clear last frame
	}

}

void ThreadAudioLoop()
{
	audbep::AudioBeepCoreLoop();
}

void ThreadConsoleLoop()
{
	while (true)
	{
		if (GetAsyncKeyState(47)) //do they want to run a command
		{
			string Output = "";

			cout << endl << "/";
			cin >> Output; //get command to run

			string OutputLeft = Output;
			string OutputRight = "1";

			if (Output.find(" ") != string::npos) //find value from input
			{
				OutputLeft = Output.substr(0, Output.find(" ") - 1);
				OutputRight = Output.substr(Output.find(" ") + 1, Output.length() - (Output.find(" ") + 2));
			}

			EngineSettings::CommandConsoleCMD.Fire( OutputLeft, OutputRight ); //runs command
		}

		Sleep(EngineSettings::MinmalRenderDelayInMircoSeconds); //sleep so we problay wont mess up rendering
	}
}

int main()
{
	vector <thread> threads;

	thread TUL(ThreadUpdateLoop);
	threads.push_back(move(TUL));

	thread TRL(ThreadRenderLoop);
	threads.push_back(move(TRL));

	thread TAL(ThreadAudioLoop);
	threads.push_back(move(TAL));

	if (EngineSettings::ConsoleAllowed == true)
	{
		thread TCL(ThreadConsoleLoop);
		threads.push_back(move(TCL));
	}

	for (auto& t : threads)
	{
		t.join();
	}

	GameMain(); //starts game loop
}

