
#include "g_e_PostProcessingTrigger.h"

void g_e_PostProcessingTrigger::OnTriggerInterraction(BaseEntity* Ent, bool TrueIfEnteringFalseIfLeaving)
{
	delete EngineSettings::GetUpToDateValue("PostPorcessingShader", TYPE_REP(BaseRenderingModifier));

	if(TrueIfEnteringFalseIfLeaving == true)
	{
		EngineSettings::ChangeInRunTime("PostPorcessingShader", PostProcessMaterial);
	}
	else
	{
		EngineSettings::ChangeInRunTime("PostPorcessingShader", (BaseRenderingModifier*)nullptr);
	}
}


void g_e_PostProcessingTrigger::SetPostProcessingMaterial(BaseRenderingModifier* Mat)
{
	PostProcessMaterial = Mat;
}

void g_e_PostProcessingTrigger::SetEndlessExtent(bool NewExtent)
{
	if (HasEndlessExtent == false && NewExtent == true)
	{
		HasEndlessExtent = true;
		SetKeyValue("PosX", to_string(MyOffset.X - 80000));
		SetKeyValue("PosY", to_string(MyOffset.Y - 80000));
		SetKeyValue("SizeX", to_string(MySize.X + (80000 * 2)));
		SetKeyValue("SizeY", to_string(MySize.Y + (80000 * 2)));
	}

	if (HasEndlessExtent == true && NewExtent == false)
	{
		HasEndlessExtent = false;
		SetKeyValue("PosX", to_string(MyOffset.X + 80000));
		SetKeyValue("PosY", to_string(MyOffset.Y + 80000));
		SetKeyValue("SizeX", to_string(MySize.X - (80000 * 2)));
		SetKeyValue("SizeY", to_string(MySize.Y - (80000 * 2)));
	}
}
