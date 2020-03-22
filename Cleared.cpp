#include <iostream>


#include "Cleared.h"
#include "Utility.h"
#include "WordManager.h"

using namespace std;

Cleared::Cleared()
{
}

void Cleared::ClearedWord(struct WordInformation *wordInfor, int &iWordArr,
				          int &iItemLimitCount, int &iItemNumber, bool *iItemAlive)
{
	WordManager cWordManager;

		if (iItemLimitCount == 1)
		{
			Utility::GetUtility()->gotoxy(0, 0);
			cout << "                     ";
			Utility::GetUtility()->gotoxy(0, 0);
			cout << "Cleared";


			cWordManager.RegenerationWord(wordInfor, iWordArr);
			iWordArr = 0;

			iItemLimitCount = 0;
			iItemNumber = 0;
			*iItemAlive = false;
		}

		else
		{
			for (int i = 0; i < MAXWORDCOUNT; i++)
			{
				if (wordInfor[i].bWordAlive = true)
				{
					wordInfor[i].bWordAlive = false;
					Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 1);
					cout << "           ";
				}
			}
	iItemLimitCount++;
		}







	//Utility::GetUtility()->gotoxy(0, 0);
	//cout << "                     ";
	//Utility::GetUtility()->gotoxy(0, 0);
	//cout << "Cleared";

	//for (int i = 0; i < MAXWORDCOUNT; i++)
	//{
	//	if (wordInfor[i].bWordAlive = true)
	//	{
	//		wordInfor[i].bWordAlive = false;
	//		Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 1);
	//		cout << "           ";
	//	}
	//}
	//cWordManager.RegenerationWord(wordInfor, iWordArr);
	//iWordArr = 0;
}

Cleared::~Cleared()
{
}
