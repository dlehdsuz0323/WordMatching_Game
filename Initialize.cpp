#include <iostream>
#include <Windows.h>
#include "Initialize.h"
#include "Word.h"

using namespace std;

Initialize::Initialize()
{
	system("mode con cols=100 lines=100");
}

void Initialize::InitializeGameMap(int map[MAPHIGH][MAPWIDTH])
{
	for (int y = 0; y < MAPHIGH; y++)
	{
		for (int x = 0; x < MAPWIDTH; x++)
		{
			map[y][x] = EMPTY;
		}
	}

	for (int x = 0; x < MAPWIDTH; x++)
	{
		map[1][x] = UWALL;		//À­ÂÊ
	}

	for (int x = 0; x < MAPWIDTH; x++)
	{
		map[MAPHIGH - 1][x] = DWALL;	// ¾Æ·§ÂÊ
	}
}

Initialize::~Initialize()
{
}
