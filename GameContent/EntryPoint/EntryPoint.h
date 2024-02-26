#pragma once

#include "../../EngineContent/EngineSettings/EngineSettings.h"
#include "../../EngineContent/BaseEntity/BaseEntity.h"
#include "../../EngineContent/Audio/AudioBeepControl.h"

#include "../GameAssests/g_WorldLayer/g_WorldLayer.h"
#include "../GameAssests/g_m_MaterialGrass/g_m_grassmat.h"

static int GameMain()
{
	g_WorldLayer Grass = g_WorldLayer();

	RenderingInfo GrassRenderContent = RenderingInfo();
	GrassRenderContent.MyModifyer = new g_m_grassmat();
	GrassRenderContent.ContentsToRender.resize(27);
	GrassRenderContent.ContentsToRender[0] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[1] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[2] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[3] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[4] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[5] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[6] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[7] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[8] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[9] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[10] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[11] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[12] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[13] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[14] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[15] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[16] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[17] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[18] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[19] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[20] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[21] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[22] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[23] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[24] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[25] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	GrassRenderContent.ContentsToRender[26] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";

	Grass.SetRenderContents(GrassRenderContent);
	Grass.Spawn();

	while (true) {}
}