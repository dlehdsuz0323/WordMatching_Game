#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Word.h"
#include "WordManager.h"
#include "Utility.h"
#include "InputWord.h"
#include "Print.h"
#include "Score.h"
#include "LIFE.h"
#include "User.h"
#include "ItemManager.h"
#include "ScoreBoard.h"

using namespace std;
int iSpeed = 2;
int iWordSpeed = 0;

Word::Word()
{
	
}

bool Word::Update()		// Update
{
	LIFE		cLife;
	Print		cPrintGameMap;
	WordManager cManager;
	InputWord   cInput;
	Score		cScore;	
	ScoreBoard  cScoreBoard;
	ItemManager cItemManager;

	// init

		WordInformation sWord[MAXWORDCOUNT];

		LoadTheWord(sWord);
		iWordArr = 0;
		iWordSpeed = 0;
		iItemCount = 0;

		User::GetUserInformation()->InputUserName();
		User::GetUserInformation()->Init();
		sWord[iWordArr].bWordAlive = true;
		cPrintGameMap.PrintMap();
		cScore.PrintScore(User::GetUserInformation()->ReturnUserInfo()->iScore);
		cScore.Stage(User::GetUserInformation()->ReturnUserInfo()->iScore, iStageCount);

		char input;

		while (true)
		{
			Utility::GetUtility()->gotoxy(0, 40);
			cout << "Speed: " << iSpeed;

			if (kbhit())
				strcpy(chWord, cInput.Checktheword());
			Sleep(1000/20);

			TheWordCrashesOnTheFloor(sWord, User::GetUserInformation()->ReturnUserInfo()->iLife);
			if (cLife.CheckLife(User::GetUserInformation()->ReturnUserInfo()->iLife) == false)
				break;

			if (iWordSpeed > 25)
			{

				OutputWord(sWord, iWordArr);
				iWordSpeed = iSpeed;

				while (true)
				{
					if (iWordNewLine == false)
					{
						iWordNewLine = true;
						break;

					}

					else if (iWordNewLine == true)
					{
						iWordNewLine = false;
						sWord[iWordArr].bWordAlive = true;						
						iWordArr++;
						break;
					}

				}

			}

					if (sWord[iWordArr- 1].bWordAlive)
					{
						if (iItemAlive == true)
							cItemManager.RandomItem(sWord, iWordArr, iItemAlive, iItmeNumber);
					}
				CheckInputWord(sWord, chWord);


			iWordSpeed += 1;
		}

		cScoreBoard.SaveFile(User::GetUserInformation()->ReturnUserInfo()->userName,iScore);
		getch();
		return 0;
}


void Word::LoadTheWord(struct WordInformation wordInfor[MAXWORDCOUNT])
{
	WordManager manager;
	manager.LoadFileTheWord(wordInfor);
}

void Word::EraseWordInMap(struct WordInformation wordInfor[MAXWORDCOUNT])
{
	for (int j = 0; j < MAXWORDCOUNT; j++)
	{
		if (wordInfor[j].bWordAlive == true)
		{
			for (int i = 0; i < wordInfor[j].strWord.size(); i++)
			{
				cout << " ";
			}
		}
	}
}

void Word::OutputWord(struct WordInformation *wordInfor, int &iWordArr)
{
	WordManager cManager;

	for (int i = 0; i < MAXWORDCOUNT; i++)
	{
		if (wordInfor[i].bWordAlive == true)		// Item true
		{
			if (wordInfor[i].bItemWord == ITEMTRUE)
			{
				Utility::GetUtility()->TextColor(YELLOW, BLACK);

				Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y);
				cout << wordInfor[i].strWord;
				wordInfor[i].y++;

				Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 2);
				EraseWordInMap(wordInfor);

				Utility::GetUtility()->TextColor(LIGHTGRAY, BLACK);
			}
				
			else if (wordInfor[i].bItemWord == ITEMFALSE)	//  Not Item
			{
				Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y);
				cout << wordInfor[i].strWord;
				wordInfor[i].y++;

				Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 2);
				EraseWordInMap(wordInfor);

				Utility::GetUtility()->TextColor(LIGHTGRAY, BLACK);
			}	

		}
	}

	if (wordInfor[85].bWordAlive == true)
	{
		for (int i = 0; i < 50; i++)
		{
			wordInfor[i].y = 3;
		}
		if (wordInfor[99].bWordAlive == true)
			if (wordInfor[99].y > 6)
			{
				iWordArr = 0;
			}
	}
	if (wordInfor[15].bWordAlive == true)
	{
		for (int i = 50; i < MAXWORDCOUNT; i++)
		{
			wordInfor[i].y = 3;
		}
	}
}

void Word::TheWordCrashesOnTheFloor(struct WordInformation wordInfor[MAXWORDCOUNT], int &iLife)
{
	for (int i = 0; i < MAXWORDCOUNT; i++)
	{
		if (wordInfor[i].bWordAlive == true)
		{
			if (wordInfor[i].y == (MAPHIGH - 2))
			{
				Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 1);
				EraseWordInMap(wordInfor);
				wordInfor[i].bWordAlive = false;
				iLife--;
				break;
			}

			else if (
				(wordInfor[i].strWord.size() + wordInfor[i].x) > 25 &&
				(wordInfor[i].strWord.size() + wordInfor[i].x) < 40 &&
				 wordInfor[i].y == (MAPHIGH - 7))

			{
				Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 1);
				EraseWordInMap(wordInfor);
				wordInfor[i].bWordAlive = false;
				iLife--;
				break;
			}
		}
	}
}

void Word::CheckInputWord(struct WordInformation wordInfor[MAXWORDCOUNT], char *word)
{
	Score cScore;
	ItemManager cItemManager;

	for (int i = 0; i < MAXWORDCOUNT; i++)
	{
		if (wordInfor[i].bWordAlive == true)
		{
			if (wordInfor[i].strWord == word)
			{
				if (wordInfor[i].bItemWord == ITEMFALSE)
				{
					wordInfor[i].bWordAlive = false;
					Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 1);
					for (int i = 0; i < wordInfor[i].strWord.size() + 5; i++)
					{
						cout << " ";
					}

					cScore.PrintScore(iScore += 10);
					cScore.Stage(iScore, iStageCount);
					*word = NULL;
					break;
				}

				else if (wordInfor[i].bItemWord == ITEMTRUE)
				{
					iItemAlive = true;
					wordInfor[i].bWordAlive = false;
					Utility::GetUtility()->gotoxy(wordInfor[i].x, wordInfor[i].y - 1);
					for (int i = 0; i < wordInfor[i].strWord.size() + 5; i++)
					{
						cout << " ";
					}
					iItmeNumber = cItemManager.ReceivesRandomNumber();

					cScore.PrintScore(iScore += 10);
					cScore.Stage(iScore, iStageCount);

					*word = NULL;
					break;
				}
			}
		}
	}
}


Word::~Word()
{
}
