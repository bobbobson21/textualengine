#include "g_m_WorldMat.h"

string g_m_WorldMat::PreRender(int X, int Y, string RenderingFor, string OldRenderingFor)
{
	if (RenderingFor == "G")
	{
		srand(X + Y * 4145);

		switch ((int)rand() % 7)
		{
		case 1:
			SetConsoleTextAttribute(OutHandle, 170);
			break;

		case 2:
			SetConsoleTextAttribute(OutHandle, 162);
			break;

		case 3:
			SetConsoleTextAttribute(OutHandle, 34);
			break;

		case 4:
			SetConsoleTextAttribute(OutHandle, 42);
			break;

		case 5:
			SetConsoleTextAttribute(OutHandle, 43);
			break;

		case 6: default:
			SetConsoleTextAttribute(OutHandle, 171);
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
			SetConsoleTextAttribute(OutHandle, 120);
			break;

		case 2:
			SetConsoleTextAttribute(OutHandle, 127);
			break;

		case 3:
			SetConsoleTextAttribute(OutHandle, 128);
			break;

		case 4:
			SetConsoleTextAttribute(OutHandle, 112);
			break;
		default:
			SetConsoleTextAttribute(OutHandle, 7);
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
