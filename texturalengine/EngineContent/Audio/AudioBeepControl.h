#pragma once

#include <Windows.h>
#include <String>

namespace audbep //salvaged from an old project feel free to improve upone it
{
	struct AudioBeep
	{
		std::string Type = "null";
		int Time = 0;
	};

	namespace _private //I was thinking about doing this in a class because of this but visual studios wansn't likeing that idea and kept throwing non senceical errors when nthoing was wrong so I put it all in one header file and now it works fine
	{
		static const int MaxAudioBeepContentCount = 2048;
		static int AudioBeepContentCount = 0;
		static AudioBeep AudioToPush[MaxAudioBeepContentCount] = {};
	}

	static void AddAudioBeep(std::string Type, float delay = 1)
	{
		_private::AudioToPush[_private::AudioBeepContentCount] = AudioBeep{ Type ,(int)((float)delay * 100)};
		_private::AudioBeepContentCount++;
		if (_private::AudioBeepContentCount >= _private::MaxAudioBeepContentCount) { _private::AudioBeepContentCount = 0; }
		if (_private::AudioToPush[max(_private::AudioBeepContentCount -1,0)].Type == "null" && _private::AudioToPush[_private::MaxAudioBeepContentCount -1].Type == "nill" ) { _private::AudioBeepContentCount = 0; }
	}

	static void ClearAudioBeeps() //for siturations where we dont know how long the audio is
	{
		_private::AudioBeepContentCount = 0;
		for (int i = 0; i < _private::MaxAudioBeepContentCount; i++)
		{
			_private::AudioToPush[i] = AudioBeep();
		}
	}

	static void AudioBeepCoreLoop()
	{
		while (true)
		{
			for (int i = 0; i < _private::MaxAudioBeepContentCount; i++)
			{
				if (_private::AudioToPush[i].Type != "null")
				{

					if (_private::AudioToPush[i].Type == "Beep1") { Beep(200, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; } //the second prameter of Beep will do sleep for us so I set Time to zero aftwards
					if (_private::AudioToPush[i].Type == "Beep2") { Beep(300, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; } //I wanted to use an enume btw but it was easier to manage with strings when it came to addeing the other beep Types
					if (_private::AudioToPush[i].Type == "Beep3") { Beep(400, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "Beep4") { Beep(500, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; } //fyi I this design allows me to add other beep types in the future with more complex beeps if I wanted to
					if (_private::AudioToPush[i].Type == "Beep5") { Beep(600, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "Beep6") { Beep(700, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "Beep7") { Beep(800, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }

					if (_private::AudioToPush[i].Type == "LowBeep1") { Beep(28, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "LowBeep2") { Beep(56, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "LowBeep3") { Beep(86, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "LowBeep4") { Beep(114, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "LowBeep5") { Beep(142, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "LowBeep6") { Beep(170, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }
					if (_private::AudioToPush[i].Type == "LowBeep7") { Beep(198, _private::AudioToPush[i].Time); _private::AudioToPush[i].Time = 0; }

					//if (_private::AudioToPush[i].Type == "MWBeepNotice") { MessageBeep(MB_ICONERROR); } //nolonger works on win11 so it is depacrated which is a shame 
					//if (_private::AudioToPush[i].Type == "MWBeepDeny") { MessageBeep(MB_ICONEXCLAMATION); }

					Sleep(_private::AudioToPush[i].Time); //i could comment this out as well because it was mostly made for message beep but I think I will leave it encase I need it later
					_private::AudioToPush[i] = AudioBeep();
				}
			}
		}
	}
}