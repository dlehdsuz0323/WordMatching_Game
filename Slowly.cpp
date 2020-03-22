#include <iostream>

#include "Slowly.h"
#include "Utility.h"
#include "Word.h"

using namespace std;

Slowly::Slowly()
{
}

void Slowly::SlowlyWord(int &iItemLimitCount, int &iItemNumber, bool *iItemAlive)
{
	if (iItemLimitCount > 60)
	{
		iItemLimitCount = 0;
		iItemNumber = 0;
		*iItemAlive = false;
		Utility::GetUtility()->gotoxy(0, 0);
		cout << "                     ";
	}
	else
	{
		Utility::GetUtility()->gotoxy(0, 0);
		cout << "                     ";
		Utility::GetUtility()->gotoxy(0, 0);
		cout << "Slowly";

		iWordSpeed -= 1;
		iItemLimitCount ++;
	}
}

Slowly::~Slowly()
{
}
