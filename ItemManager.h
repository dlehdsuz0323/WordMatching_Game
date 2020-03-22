#pragma once

#include "Accelerate.h"
#include "Cleared.h"
#include "Disappear.h"
#include "LifeIncrease.h"
#include "Slowly.h"
#include "Stop.h"
#include "Nomal.h"

enum ItemState
{
	NOMAL,
	DISAPPEAR,
	ACCELERATE,
	CLEARED,
	LIFEINCREASE,
	SLOWLY,
	STOP,
};

class ItemManager
{
private:

	Accelerate     cAccelerate;
	Cleared        cCleared;
	Disappear      cDisappear;
	LifeIncrease   cLifeIncrease;
	Slowly         cSlowly;
	Stop           cStop;
	Nomal		   cNomal;

private:
	int iRandomItemVariable = 0;
	int iItmeNumber = 0;
	int iItemLimitCount = 0;

public:

	int ReceivesRandomNumber(void);
	void RandomItem(WordInformation *wordInfor, int &iWordArr, bool &iItemAlive,int iItmeNumber);

	ItemManager();
	~ItemManager();
};

