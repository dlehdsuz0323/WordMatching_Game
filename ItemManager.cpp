#include <iostream>
#include <time.h>

#include "WordManager.h"
#include "ItemManager.h"
#include "Utility.h"
#include "Word.h"

ItemManager::ItemManager()
{
}

int ItemManager::ReceivesRandomNumber(void)
{
	srand(time(NULL));

	iRandomItemVariable = (rand() % 6 + 1);

		return iRandomItemVariable;
}

void ItemManager::RandomItem(WordInformation *wordInfor, int &iWordArr, bool &iItemAlive, int iItmeNumber)
{

	switch (iItmeNumber)
	{
	case NOMAL:			// o
		cNomal.NomalWord();
		break;
	case DISAPPEAR:		// o
		cDisappear.DisappearWord(wordInfor, iItemLimitCount, iItmeNumber, &iItemAlive);
		break;
	case ACCELERATE:	// o
		cAccelerate.AccelerateWord(iItemLimitCount, iItmeNumber, &iItemAlive);
		break;
	case CLEARED:		// o
		cCleared.ClearedWord(wordInfor,iWordArr, iItemLimitCount, iItmeNumber, &iItemAlive);
		break;
	case LIFEINCREASE:	// o
		cLifeIncrease.LifeIncreased(iItemLimitCount, iItmeNumber, &iItemAlive);
		break;
	case SLOWLY:		// o
		cSlowly.SlowlyWord(iItemLimitCount, iItmeNumber, &iItemAlive);
		break;
	case STOP:			// o
		cStop.StopWord(iItemLimitCount, iItmeNumber, &iItemAlive);
		break;
	}
}

ItemManager::~ItemManager()
{
}
