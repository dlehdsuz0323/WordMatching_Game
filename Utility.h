#pragma once

#define BLACK 0 
#define LIGHTGRAY 7 
#define YELLOW 14 

/*
- 좌표이동
- 텍스트 색
*/

class Utility
{
private:
	Utility() {}
	static Utility* _Utility;

public:
	static Utility* GetUtility();

	void gotoxy(int x, int y);
	void TextColor(int foreground, int background);
};

