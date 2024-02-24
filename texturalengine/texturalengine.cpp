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
		auto start = chrono::high_resolution_clock::now();

		BaseEntity::ProcessUpdate(LastDeltaTime);
		Sleep(EngineSettings::MinmalUpdateDelayInMircoSeconds);

		auto end = chrono::high_resolution_clock::now();
		LastDeltaTime = (float)(end - start).count();
	}
}

void ThreadRenderLoop()
{
	while (true)
	{
		for (int y = 0; y <= EngineSettings::Ycharizals; y++)
		{
			for (int x = 0; x <= EngineSettings::Xcharizals; x++)
			{
				BaseEntity::ProcessRendering(x,y,(x == EngineSettings::Xcharizals) );
			}

		}
		Sleep(EngineSettings::MinmalRenderDelayInMircoSeconds);
		system("cls");
	}

}

void ThreadAudioLoop()
{
	audbep::AudioBeepCoreLoop();
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

	for (auto& t : threads)
	{
		t.join();
	}

	GameMain();
}

