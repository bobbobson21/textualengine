#include "g_m_PlayerMat.h"

string g_m_PlayerMat::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	if (RenderingFor == "@")
	{
		SetConsoleTextAttribute(OutHandle, 153);
		return " ";
	}
	else if (RenderingFor == "#")
	{
		SetConsoleTextAttribute(OutHandle, 102);
		return " ";
	}

	return STR_NULL;
}
