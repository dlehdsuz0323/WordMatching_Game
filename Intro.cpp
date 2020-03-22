#include <Windows.h>
#include <conio.h>
#include <iostream>

#include "Intro.h"
#include "Utility.h"
#include "Initialize.h"

using namespace std;

Intro::Intro()
{
}

void Intro::LoadIntroTextFile(vector<string> &loadVecIntro)
{
	FILE *file = fopen("IntroText.txt", "r");
	
	while (fgets(cBuffer, sizeof(cBuffer), file) != NULL)
	{
		loadVecIntro.push_back(cBuffer);
	}
	fclose(file);
}

void Intro::PrintIntro(void)
{
	iIntroSkip = 0;
	LoadIntroTextFile(vecIntro);

	for (int i = 0; i < 30; i++)
	{
		if (kbhit())
		{
			getch();
			system("cls");
			iIntroSkip = 1;
			break;
		}

		Utility::GetUtility()->gotoxy(50, i + 4);

			cout << vecIntro[i];

		Sleep(1000 / 30);
	}

	while(iIntroSkip == 0)
	{
		if (kbhit())
		{
			getch();
			system("cls");
			break;
		}
		for (int i = 0; i < 30; i++)
		{
			Utility::GetUtility()->gotoxy(50, i + 4);
			if (i >= vecIntro.size())
			{
				break;
			}
				cout << vecIntro[i];
		}

		if(vecIntro.size() != 0)
		{ 
			vecIntro.erase(vecIntro.begin() + 0);
		}
		else if (vecIntro.size() == 0)
		{
			break;
		}

		Sleep(1000 / 20);
		system("cls");
	}	
}

Intro::~Intro()
{
}
