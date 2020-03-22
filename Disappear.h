#pragma once
#include "Initialize.h"
class Disappear
{
public:

	void DisappearWord(struct WordInformation wordInfor[MAXWORDCOUNT], int &iLimitCount, int &iItemNumber, bool *iItemAlive);
	Disappear();
	~Disappear();
};

