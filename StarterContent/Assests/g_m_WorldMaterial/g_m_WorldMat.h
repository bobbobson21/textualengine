#pragma once

	#include "../../../EngineContent/BaseRenderingModifier/BaseRenderingModifier.h"

class g_m_WorldMat : public virtual BaseRenderingModifier
{
protected:
	string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor) override;
};

