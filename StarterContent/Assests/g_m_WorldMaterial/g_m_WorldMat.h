#pragma once

	#include "../../../EngineContent/RenderingModifier/RenderingModifier.h"

class g_m_WorldMat : public virtual RenderingModifier
{
public:
	string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor) override;
};

