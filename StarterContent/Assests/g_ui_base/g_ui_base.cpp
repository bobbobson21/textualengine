#include "g_ui_Base.h"
#include "../../../EngineContent/EngineSettings/EngineSettings.h"

void g_ui_Base::Update(float DeltaTime)
{
	MatainScreenAttachment();
}

void g_ui_Base::OnKeyValueSet(string Key, string Value)
{
	OnKeyValueSetBase(Key, Value);
}

void g_ui_Base::OnKeyValueSetBase(string Key, string Value)
{
	if (Key == "Anchor")
	{
		if (Key.find(" ") != string::npos)
		{
			try
			{
				SetKeyValue("AnchorX", Key.substr(0, Key.find(" ") - 1));
				SetKeyValue("AnchorY", Key.substr(Key.find(" ") + 1, Key.size() - Key.find(" ")));
			}
			catch (...) {}
		}

	}

	if (Key == "AnchorX")
	{
		try
		{
			AnchorX = (int)stof(Value);
		}
		catch (...) {};
	}

	if (Key == "AnchorY")
	{
		try
		{
			AnchorY = (int)stof(Value);
		}
		catch (...) {};
	}


	if (Key == "AnchorDirection")
	{
		if (Key.find(" ") != string::npos)
		{
			try
			{
				SetKeyValue("AnchorDirectionX", Key.substr(0, Key.find(" ") - 1));
				SetKeyValue("AnchorDirectionY", Key.substr(Key.find(" ") + 1, Key.size() - Key.find(" ")));
			}
			catch (...) {}
		}

	}

	if (Key == "AnchorDirectionX")
	{
		try
		{
			AnchorDirectionX = (int)stof(Value);
		}
		catch (...) {};
	}

	if (Key == "AnchorDirectionY")
	{
		try
		{
			AnchorDirectionY = (int)stof(Value);
		}
		catch (...) {};
	}


	if (Key == "AnchorSize")
	{
		if (Key.find(" ") != string::npos)
		{
			try
			{
				SetKeyValue("AnchorSizeX", Key.substr(0, Key.find(" ") - 1));
				SetKeyValue("AnchorSizeY", Key.substr(Key.find(" ") + 1, Key.size() - Key.find(" ")));
			}
			catch (...) {}
		}

	}

	if (Key == "AnchorSizeX")
	{
		try
		{
			AnchorSizeX = (int)stof(Value);
		}
		catch (...) {};
	}

	if (Key == "AnchorSizeY")
	{
		try
		{
			AnchorSizeY = (int)stof(Value);
		}
		catch (...) {};
	}

	if (Key == "Importance")
	{
		try
		{
			MyRenderingInfo.Importance = (int)stof(Value);
		}
		catch (...) {};
	}
}

void g_ui_Base::MatainScreenAttachment()
{
	MyRenderingInfo.PostProcessingProof = true;
	MyRenderingInfo.OffsetX = (int)((float)EngineSettings::GetUpToDateValue("RenderOffsetX", TYPE_REP(int)) + ((float)EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)) * AnchorX) + ((float)AnchorSizeX * AnchorDirectionX));
	MyRenderingInfo.OffsetY = (int)((float)EngineSettings::GetUpToDateValue("RenderOffsetY", TYPE_REP(int)) + ((float)EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)) * AnchorY) + ((float)AnchorSizeY * AnchorDirectionX));
}

void g_ui_Base::SetRenderingModifer(RenderingModifier* RenderMod)
{
	delete MyRenderingInfo.MyModifyer;
	MyRenderingInfo.MyModifyer = RenderMod;
}

void g_ui_Base::SetImportance(int Importance)
{
	MyRenderingInfo.Importance = Importance;
}
