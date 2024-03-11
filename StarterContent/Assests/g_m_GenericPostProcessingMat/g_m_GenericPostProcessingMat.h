#pragma once

	#include "../../../EngineContent/RenderingModifier/RenderingModifier.h"

class g_m_GenericPostProcessingMat : public virtual RenderingModifier
{
protected:
	string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor) override;
};

