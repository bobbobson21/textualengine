#include "g_m_PlayerMat.h"

string g_m_PlayerMat::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	if (RenderingFor == "@")
	{
		SetReturnAttribute(153);
		return " ";
	}
	else if (RenderingFor == "#")
	{
		SetReturnAttribute(102);
		return " ";
	}

	return STR_NULL;
}
