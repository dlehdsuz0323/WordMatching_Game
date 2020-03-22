#include <iostream>
#include <Windows.h>

#include "Disappear.h"
#include "Utility.h"

using namespace std;

Disappear::Disappear()
{
}

void Disappear::DisappearWord(struct WordInformation wordInfor[MAXWORDCOUNT], int &iItemLimitCount, int &iItemNumber, bool *iItemAlive)
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
		cout << "Disappear";
		for (int i = 0; i < MAXWORDCOUNT; i++)
		{
			if (wordInfor[i].bWordAlive == true)
			{
				Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 1);
				for (int j = 0; j < wordInfor[i].strWord.size(); j++)
				{
					cout << "*";
				}
			}
		}
		iItemLimitCount++;
	}

}

Disappear::~Disappear()
{
}
