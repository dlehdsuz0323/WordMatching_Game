#include <iostream>
#include <Windows.h>

#include "Score.h"
#include "Utility.h"
#include "Initialize.h"
#include "User.h"

using namespace std;
extern int iSpeed;

Score::Score()
{
}

void Score::PrintScore(int &iScore)
{
	Utility::GetUtility()->gotoxy(MAPWIDTH / 2, 0);
	cout << "Score : " << iScore;
}

void Score::Stage(int &iScore, int &iStageCount)
{
	Utility::GetUtility()->gotoxy(MAPWIDTH  - 10, 0);

	if (iScore >= 100)
	{
		if (0 == iScore % 100)
		{
			iSpeed++;
			iStageCount++;
		}
	}

	cout << "stage: " << iStageCount;
}

Score::~Score()
{
}
