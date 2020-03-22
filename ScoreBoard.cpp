#include <iostream>

#include "ScoreBoard.h"
#include "Utility.h"
#include "Initialize.h"

using namespace std;

ScoreBoard::ScoreBoard()
{	
}

void ScoreBoard::SaveFile(string userName, int iScore)
{
	FILE *RankingCount = fopen("RankingCount.txt", "r+");

	LoadFile(userRanking);	

	if (RankingCount != NULL)
	{
		iMaxRankingCount = 0;
		fscanf(RankingCount, "%d", &iMaxRankingCount);
		FILE *RankingCount = fopen("RankingCount.txt", "w");

		
		if (iMaxRankingCount < MAXRAKINGCOUNT )
		{
			userRanking[iMaxRankingCount].userName = userName;
			userRanking[iMaxRankingCount].iScore = iScore;
			SortRanking(userRanking, iMaxRankingCount);
			iMaxRankingCount++;
		}
		else if (iMaxRankingCount == 10)
		{
			OverwriteScore(userName,iScore);
		}

			FILE *SaveFile = fopen("Ranking.txt", "w+");
			for (int i = 0; i < MAXRAKINGCOUNT; i++)
			{
				if (userRanking[i].userName == "기록없음")
					break;
				
				else
				fprintf(SaveFile, "%s %d\n", userRanking[i].userName.c_str(), userRanking[i].iScore);
			}

	fclose(SaveFile);			 
	fprintf(RankingCount, "%d", iMaxRankingCount);
	fclose(RankingCount);
	}
}

void ScoreBoard::LoadFile(UserInformation *userRanking)
{
	char cName[128];

	FILE *LoadFile = fopen("Ranking.txt", "r");
	FILE *RankingCount = fopen("RankingCount.txt", "r");

	if (LoadFile != NULL)
	{
		fscanf(RankingCount, "%d", &iMaxRankingCount);
		for (int i = 0; i < iMaxRankingCount; i++)
		{
			fscanf(LoadFile,"%s %d\n",cName, 
			&User::GetUserInformation()->ReturnUserInfo()->iScore);

			User::GetUserInformation()->ReturnUserInfo()->userName = cName;

			userRanking[i].userName = User::GetUserInformation()->ReturnUserInfo()->userName;
			userRanking[i].iScore = User::GetUserInformation()->ReturnUserInfo()->iScore;
		}
		fclose(LoadFile);
	}
		fclose(RankingCount);
}

void ScoreBoard::PrintScoreBoard(void)
{
	LoadFile(userRanking);

	if (User::GetUserInformation()->ReturnUserInfo()->userName.size() == 0)
	{
		Utility::GetUtility()->gotoxy(MAPWIDTH / 2, 10);
		cout<< " 랭킹이 없습니다 ";
	}


	else
	{
		Utility::GetUtility()->gotoxy(MAPWIDTH / 2, 10);
		cout << "이름";
		Utility::GetUtility()->gotoxy(MAPWIDTH / 2 + 10, 10);
		cout << "점수";

		for (int i = 0; i < iMaxRankingCount; i++)
		{
			Utility::GetUtility()->gotoxy(MAPWIDTH / 2, 11 + i);
			cout << userRanking[i].userName;
			Utility::GetUtility()->gotoxy(MAPWIDTH / 2 + 10, 11 + i);
			cout << userRanking[i].iScore;
		}
	}
}

void ScoreBoard::SortRanking(UserInformation *Ranking,int iMaxRankingCount)
{

	int arr[10] = { 3,5,7,8,5,3,2,6,9,0 };


	for (int i = 0; i < iMaxRankingCount; i++)
	{
		for (int j = i; j < iMaxRankingCount; j++)
		{
			if (Ranking[i].iScore < Ranking[j].iScore)
			{
				UserInformation temp = Ranking[i];
				Ranking[i] = Ranking[j];
				Ranking[j] = temp;
			}
		}
	}
}

void ScoreBoard::OverwriteScore(string &userName, int &iScore)
{

	FILE *LoadFile = fopen("Ranking.txt", "r");
	UserInformation temp[11];
	char cName[128];

	for (int i = 0; i < MAXRAKINGCOUNT; i++)
	{
		fscanf(LoadFile, "%s %d\n",cName, &userRanking[i].iScore);
		userRanking[i].userName = cName;
	}

	if (iMaxRankingCount == MAXRAKINGCOUNT)
	{
		iMaxRankingCount = 11;
		for (int i = 0; i < MAXRAKINGCOUNT; i++)
		{
			temp[i] = userRanking[i];
		}

		temp[10].userName = userName;
		temp[10].iScore = iScore;

		SortRanking(temp, iMaxRankingCount);

		for (int i = 0; i < MAXRAKINGCOUNT; i++)
		{
			userRanking[i] = temp[i];
		}
		iMaxRankingCount = 10;
	}

	fclose(LoadFile);
}

ScoreBoard::~ScoreBoard()
{
}
