#pragma once

#include "Initialize.h"
#include "WordManager.h"

class Print
{
private:

	int iMap[MAPHIGH][MAPWIDTH];

public:
	void PrintMap(void);
	
	Print();
	~Print();
};

