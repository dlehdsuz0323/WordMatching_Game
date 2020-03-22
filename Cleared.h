#pragma once

#include "Initialize.h"

class Cleared
{
public:
	void ClearedWord(struct WordInformation *wordInfor, int &iWordArr,
		int &iItemLimitCount, int &iItemNumber, bool *iItemAlive);

	Cleared();
	~Cleared();
};

