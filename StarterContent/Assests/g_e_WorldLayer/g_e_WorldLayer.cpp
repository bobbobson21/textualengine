#include "g_e_WorldLayer.h"

void g_e_WorldLayer::Start()
{
}

void g_e_WorldLayer::SetRenderContents(BaseEntity_RenderingInfo Rend)
{
	MyRenderingInfo = Rend;
}

void g_e_WorldLayer::ReceiveFireInstruction(string Message, string Value)
{
	if (Message == "CollectRenderingDataFromBaseLevelSystem")
	{
		MyRenderingInfo = BaseLevelSystem::CollectRenderingData();
	}
}


