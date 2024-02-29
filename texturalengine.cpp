// teXturalengine.cpp : This file contains the 'main' function. Program eXecution begins and ends there.
//

#include <iostream>
#include <Thread>
#include <Vector>
#include <chrono>
#include <Windows.h>

#include "EngineContent/EngineSettings/EngineSettings.h"
#include "EngineContent/BaseEntity/BaseEntity.h"
#include "EngineContent/Audio/AudioBeepControl.h"

#include "GameContent/EntryPoint/EntryPoint.h"

using namespace std;

	float DeltaTime = 0;

	bool IsRendering = false;
	bool IsInConsole = false;

void ThreadUpdateLoop()
{
	float LastDeltaTime = 0;

	while (true)
	{
		if (IsInConsole == false)
		{
			auto start = chrono::high_resolution_clock::now(); //delta time start

			BaseEntity::ProcessUpdate(LastDeltaTime); //updates all entities
			Sleep(EngineSettings::GetUpToDateValue("MinmalUpdateDelayInMircoSeconds", TYPE_REP(int)));
			
			auto end = chrono::high_resolution_clock::now(); //delta time end
			LastDeltaTime = (float)(end - start).count(); //calulate delta time
			DeltaTime = LastDeltaTime;
		}
	}
}

void ThreadRenderLoop()
{
	HANDLE ConOut = GetStdHandle(STD_OUTPUT_HANDLE);

	//for (int i = 0; i < 255; i++)
	//{
	//	SetConsoleTextAttribute(ConOut, i);

	//	cout << i << endl;
	//}


	while (true)
	{
		if (IsInConsole == false)
		{
			IsRendering = true;

			for (int Y = 0; Y <= EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)); Y++) //what line should be rendered
			{
				for (int X = 0; X <= EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)); X++) //starts to render a line of charizals
				{
					BaseEntity::ProcessRendering(X + EngineSettings::GetUpToDateValue("RenderOffsetX", TYPE_REP(int)), Y + EngineSettings::GetUpToDateValue("RenderOffsetY", TYPE_REP(int)), (X == EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)))); //dose the real rendering
					SetConsoleTextAttribute(ConOut, EngineSettings::GetUpToDateValue("VoidRenderColor", TYPE_REP(int))); //the color of nothing
				}

			}

			Sleep(EngineSettings::GetUpToDateValue("MinmalRenderDelayInMircoSeconds", TYPE_REP(int)));
			IsRendering = false;

			system("cls"); //clear last frame
		}
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
		if (GetAsyncKeyState('C') && IsRendering == false) //do they want to run a command
		{
			IsInConsole = true;

			string Output = "";

			cin.clear();
			cin.fail();
			getline(cin, Output); //get command to run

			string OutputLeft = Output;
			string OutputRight = "1";

			if (Output.find(" ") != string::npos) //find value from input
			{
				OutputLeft = Output.substr(0, Output.find(" ") );
				OutputRight = Output.substr(Output.find(" ") + 1, Output.length() - (Output.find(" ") + 1));
			}

			EngineSettings::GetConstValue( "CommandConsoleCMD", TYPE_REP(BaseEntity) )->Fire(OutputLeft, OutputRight); //runs command
			IsInConsole = false;
		}

	}
}

void ExitMain() //games ending
{
	BaseEntity::RemoveAll();
	delete EngineSettings::GetConstValue("CommandConsoleCMD", TYPE_REP(BaseEntity));
}

int main()
{
	atexit(ExitMain);

	vector <thread> threads;

	thread TUL(ThreadUpdateLoop);
	threads.push_back(move(TUL));

	thread TRL(ThreadRenderLoop);
	threads.push_back(move(TRL));

	thread TAL(ThreadAudioLoop);
	threads.push_back(move(TAL));

	thread TGL(GameMain);
	threads.push_back(move(TGL));

	if (EngineSettings::GetUpToDateValue( "ConsoleAllowed", TYPE_REP(bool) ) == true)
	{
		thread TCL(ThreadConsoleLoop);
		threads.push_back(move(TCL));
	}

	for (auto& t : threads)
	{
		t.join();
	}
}

