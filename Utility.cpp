#include <Windows.h>

#include "Utility.h"



Utility* Utility::_Utility;

Utility* Utility::GetUtility()
{
	_Utility = new Utility();

	return _Utility;
}

void Utility::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Utility::TextColor(int foreground, int background)
{
		int color = foreground + background * 16;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}