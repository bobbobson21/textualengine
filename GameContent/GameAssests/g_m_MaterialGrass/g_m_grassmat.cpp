#include "g_m_grassmat.h"

string g_m_grassmat::PreRender(int X, int Y)
{
	srand(X + Y);

	HANDLE conout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(conout, ColorOveride);

	switch (rand() % 7)
	{
	case 1:
		SetConsoleTextAttribute(conout, 170);
		break;

	case 2:
		SetConsoleTextAttribute(conout, 162);
		break;

	case 3:
		SetConsoleTextAttribute(conout, 34);
		break;

	case 4:
		SetConsoleTextAttribute(conout, 42);
		break;

	case 5:
		SetConsoleTextAttribute(conout, 43);
		break;

	case 6: default:
		SetConsoleTextAttribute(conout, 171);
		break;
	}

	return STR_NULL;
}
