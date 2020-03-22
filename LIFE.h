#pragma once

#include "Initialize.h"


//extern int iLife;

enum LifeType
{
	LIFE_AVLIVE = 9,
	LIFE_LOSE,
};

class LIFE
{
private:
	int lifeCheck = 0;
public:

	bool CheckLife(int &iLife);

	LIFE();
	~LIFE();
};