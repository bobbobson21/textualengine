#pragma once

	#include "../../../EngineContent/RenderingModifier/RenderingModifier.h"

class g_m_PlayerMat: public virtual RenderingModifier
{
public:
	string PreRender(int X, int Y, string RenderingFor, string OldRenderingFor) override;
};

