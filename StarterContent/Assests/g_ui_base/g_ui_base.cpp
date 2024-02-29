#include "g_ui_base.h"
#include "../../../EngineContent/EngineSettings/EngineSettings.h"

void g_ui_base::Update(float DeltaTime)
{
	MatainScreenAttachment();
}

void g_ui_base::MatainScreenAttachment()
{
	MyRenderingInfo.OffsetY = EngineSettings::GetUpToDateValue("RenderOffsetY", TYPE_REP(int)) + (EngineSettings::GetConstValue("YCharizals", TYPE_REP(int)) * AnchorY) + AnchorOffsetY;
	MyRenderingInfo.OffsetX = EngineSettings::GetUpToDateValue("RenderOffsetX", TYPE_REP(int)) + (EngineSettings::GetConstValue("XCharizals", TYPE_REP(int)) * AnchorX) + AnchorOffsetX;
}
