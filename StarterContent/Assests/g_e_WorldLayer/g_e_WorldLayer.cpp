#include "g_e_WorldLayer.h"

void g_e_WorldLayer::SetRenderContents(BaseEntity_RenderingInfo Rend)
{
	delete MyRenderingInfo.MyModifyer;
	MyRenderingInfo = Rend;
}

void g_e_WorldLayer::ReceiveFireInstruction(string Message, string Value)
{
	if (Message == "CollectRenderingDataFromBaseLevelSystem")
	{
		SetRenderContents( BaseLevelSystem::CollectRenderingData() );
	}
}


