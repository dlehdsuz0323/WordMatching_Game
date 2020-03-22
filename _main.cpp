#include <iostream>
#include <conio.h>
#include <Windows.h>


#include "Utility.h"
#include "Print.h"
#include "Word.h"
#include "User.h"
#include "Intro.h"
#include "ScoreBoard.h"

using namespace std;

enum GAME
{
	GAMEPLAY = 1,
	GAMESCORE,
	PROGRAMEXIT,
	TESTCODE
};

void PrintMenu(void);

void main(void)
{
	int iSelectMenu = 0;

	Print cPrintGyameMap;
	Word cWord;
	Intro cIntro;
	ScoreBoard cScoreBoard;
	User cUser;

	cIntro.PrintIntro();


	while (true)
	{

		system("cls");
		PrintMenu();

		Utility::GetUtility()->gotoxy(50, 15);
		cin >> iSelectMenu;
		system("cls");


		switch (iSelectMenu)
		{
		case GAMEPLAY:

			while (true)
			{
				system("cls");
				cWord.Update();
				break;
			}
			break;

		case GAMESCORE:
			cScoreBoard.PrintScoreBoard();
			getch();
			break;

		case PROGRAMEXIT:
			exit(0);
			break;
		}
	}
}

void PrintMenu(void)
{
	Utility::GetUtility()->gotoxy(50, 10);
	cout << "1. Play Game" << endl;
	Utility::GetUtility()->gotoxy(50, 11);
	cout << "2. Score Board" << endl;
	Utility::GetUtility()->gotoxy(50, 12);
	cout << "3. Exit" << endl;
}