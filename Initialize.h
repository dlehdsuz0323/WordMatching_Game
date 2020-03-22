#pragma once
#include "WordManager.h"

#define MAPHIGH 40
#define MAPWIDTH 50

enum WallType
{
	EMPTY,

	UWALL,
	DWALL,

	EWORD
};

class Initialize
{
public:
	void InitializeGameMap(int map[MAPHIGH][MAPWIDTH]);

	Initialize();
	~Initialize();
};

