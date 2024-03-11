#include "g_m_GenericPostProcessingMat.h"

string g_m_GenericPostProcessingMat::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	SetReturnAttribute(GetOldReturnAttribute() + 16);

	return STR_NULL;
}
