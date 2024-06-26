// teXturalengine.cpp : This file contains the 'main' function. Program eXecution begins and ends there.
//

#include <iostream>
#include <Thread>
#include <Vector>
#include <chrono>
#include <Windows.h>

#include "EngineContent/EngineSettings/EngineSettings.h"
#include "EngineContent/BaseEntity/BaseEntity.h"
#include "EngineContent/BaseSaveSystem/BaseSaveSystem.h"
#include "EngineContent/Audio/AudioBeepControl.h"

#include "GameContent/EntryPoint/EntryPoint.h"

using namespace std;

	float DeltaTime = 0;

	bool IsRendering = false;
	bool IsInConsole = false;
	bool BreakRendering = false;

void ThreadUpdateLoop()
{
	float LastDeltaTime = 0;
	int TicksSinceLastDeletion = 0;

	while (true)
	{
		if (IsInConsole == false)
		{
			if (TicksSinceLastDeletion >= 2)
			{
				TicksSinceLastDeletion = 0;
				BaseEntity::ProcessFinalRemoval();
			}

			auto Start = chrono::high_resolution_clock::now(); //delta time start

			BaseEntity::ProcessUpdate(LastDeltaTime); //updates all entities

			this_thread::sleep_for(std::chrono::milliseconds(EngineSettings::GetUpToDateValue("MinmalUpdateDelayInMilliSeconds", TYPE_REP(int))));

			auto End = chrono::high_resolution_clock::now(); //delta time end
			LastDeltaTime = (float)(End - Start).count() /100000; //calulate delta time
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
			BaseRenderingModifier::SetScreenCord(EngineSettings::GetUpToDateValue("RenderOffsetX", TYPE_REP(int)), EngineSettings::GetUpToDateValue("RenderOffsetY", TYPE_REP(int)));

			IsRendering = true;

			for (int Y = 0; Y <= EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)); Y++) //what line should be rendered
			{
				for (int X = 0; X <= EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)); X++) //starts to render a line of charizals
				{
					BaseEntity::ProcessRendering({ X + EngineSettings::GetUpToDateValue("RenderOffsetX", TYPE_REP(int)), Y + EngineSettings::GetUpToDateValue("RenderOffsetY", TYPE_REP(int)) }, (X == EngineSettings::GetConstValue("XCharizals", TYPE_REP(int))), EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(BaseRenderingModifier))); //dose the real rendering howver it dose not do screen refreshes
					SetConsoleTextAttribute(ConOut, EngineSettings::GetUpToDateValue("VoidRenderColor", TYPE_REP(int))); //the color of nothing
				}

			}

			this_thread::sleep_for(std::chrono::milliseconds(EngineSettings::GetUpToDateValue("MinmalRenderDelayInMilliSeconds", TYPE_REP(int))));

			//system("cls");
			cout << "\033[10" + to_string(EngineSettings::GetConstValue("YCharizals", TYPE_REP(int))) + "A"; //better way of doing a screen refresh

			IsRendering = false;
		}
	}
}

void ThreadAudioLoop()
{
	audbep::AudioBeepCoreLoop();
}

void ThreadConsoleLoop()
{
	HANDLE ConOut = GetStdHandle(STD_OUTPUT_HANDLE);

	while (true)
	{
		if (GetAsyncKeyState('C') && IsRendering == false) //do they want to run a command
		{
			IsInConsole = true;
			string Output = "";

			cin.clear();
			getline(cin, Output); //get command to run
			cin.clear();

			string OutputLeft = Output;
			string OutputRight = "1";

			system("cls");

			if (Output.find(" ") != string::npos) //find value from input
			{
				OutputLeft = Output.substr(0, Output.find(" ") );
				OutputRight = Output.substr(Output.find(" ") + 1, Output.length() - (Output.find(" ") + 1));
			}

			if (EngineSettings::GetConstValue("CommandConsoleCMD", TYPE_REP(BaseEntity)) != nullptr)
			{
				EngineSettings::GetConstValue("CommandConsoleCMD", TYPE_REP(BaseEntity))->Fire(OutputLeft, OutputRight); //runs command
			}
			IsInConsole = false;
		}
	}
}

void ExitMain() //games ending
{
	BreakRendering = true;

	BaseEntity::RemoveAll();

	if (EngineSettings::GetConstValue("CommandConsoleCMD", TYPE_REP(BaseEntity)) != nullptr)
	{
		delete EngineSettings::GetConstValue("CommandConsoleCMD", TYPE_REP(BaseEntity));
	}

	if (EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(BaseRenderingModifier)) != nullptr)
	{
		delete EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(BaseRenderingModifier));
	}

	BaseEntity::ProcessFinalRemoval();
}

int main()
{
	system("cls"); //running this alllows ansi codes work ... I dont know why set console mode ENABLE_VERTURAL_TERMINAL_PROCESSING dosent do that and that is fustrating

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

