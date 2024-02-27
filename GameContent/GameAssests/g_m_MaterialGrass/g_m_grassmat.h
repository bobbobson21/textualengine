#pragma once

	#include "../../../EngineContent/RenderingModifier/RenderingModifier.h"

class g_m_grassmat : public virtual RenderingModifier
{
public:
	string PreRender(int X, int Y, string RenderingFor) override;
};

