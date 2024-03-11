#include "g_e_WorldLayer.h"

void g_e_WorldLayer::Start()
{
	Identifyer = "WorldLayer";
}

void g_e_WorldLayer::SetRenderContents(BaseEntity_RenderingInfo Rend)
{
	MyRenderingInfo = Rend;
}


