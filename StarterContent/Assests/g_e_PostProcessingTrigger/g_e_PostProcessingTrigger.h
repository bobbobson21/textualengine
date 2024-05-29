#pragma once

#include "../g_e_Trigger/g_e_Trigger.h"
#include "../../../EngineContent/EngineSettings/EngineSettings.h"

class g_e_PostProcessingTrigger : virtual public g_e_Trigger
{
private:
	BaseRenderingModifier* PostProcessMaterial = nullptr;
	bool HasEndlessExtent = false;

protected:
	void OnTriggerInterraction(BaseEntity* Ent, bool TrueIfEnteringFalseIfLeaving) override;

public:
	void SetPostProcessingMaterial(BaseRenderingModifier* Mat); //this will delete the mat on entity removal so make it with new
	void SetEndlessExtent(bool NewExtent);


};

