#include <iostream>
#include <Windows.h>

#include "Initialize.h"
#include "Stop.h"
#include "Utility.h"
#include "Word.h"

using namespace std;

Stop::Stop()
{
}

void Stop::StopWord(int &iLimitCount, int &iItemNumber, bool *iItemAlive)
{
	if (iLimitCount == 30)
	{
		iLimitCount = 0;
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
		cout << "Stop";

		iWordSpeed = -100;
		iLimitCount++;
	}
}

Stop::~Stop()
{
}
