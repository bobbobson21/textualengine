#include "g_m_grassmat.h"

string g_m_grassmat::PreRender(int X, int Y, string RenderingFor)
{
	srand(X + Y *4145);

	SetConsoleTextAttribute(OutHandle, ColorOveride);

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

	if (((int)rand() % 3) == 1) { return "["; }
	if (((int)rand() % 3) == 1) { return "]"; }

	return STR_NULL;
}
