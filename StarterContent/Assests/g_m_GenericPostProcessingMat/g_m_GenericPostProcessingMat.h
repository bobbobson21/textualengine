#pragma once

	#include "../../../EngineContent/BaseRenderingModifier/BaseRenderingModifier.h"

class g_m_GenericPostProcessingMat : public virtual BaseRenderingModifier
{
protected:
	string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor) override;
};

