#include "g_m_WorldMat.h"

string g_m_WorldMat::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	if (RenderingFor == "G")
	{
		srand(X + Y * 4145);

		switch ((int)rand() % 7)
		{
		case 1:
			SetReturnAttribute(170);
			break;

		case 2:
			SetReturnAttribute(162);
			break;

		case 3:
			SetReturnAttribute(34);
			break;

		case 4:
			SetReturnAttribute(42);
			break;

		case 5:
			SetReturnAttribute(43);
			break;

		case 6: default:
			SetReturnAttribute(171);
			break;
		}

		if (((int)rand() % 3) == 1) { return "#"; }
		if (((int)rand() % 3) == 1) { return "*"; }

		return "@";
	}
	else if (RenderingFor == "|")
	{
		srand(X + Y * 4);

		switch ((int)rand() % 7)
		{
		case 1:
			SetReturnAttribute(120);
			break;

		case 2:
			SetReturnAttribute(127);
			break;

		case 3:
			SetReturnAttribute(128);
			break;

		case 4:
			SetReturnAttribute(112);
			break;
		default:
			SetReturnAttribute(7);
			break;
		}

		if (((int)rand() % 3) == 1) { return ":"; }
		if (((int)rand() % 3) == 1) { return ";"; }
		if (((int)rand() % 3) == 1) { return "="; }
		if (((int)rand() % 3) == 1) { return "_"; }
		if (((int)rand() % 3) == 1) { return "-"; }
		return "|";
	}

	return STR_NULL;
}
