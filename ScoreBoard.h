#pragma once
#include "User.h"

#define MAXRAKINGCOUNT 10

class ScoreBoard
{
private:
	UserInformation	userRanking[10];
	int iMaxRankingCount;
public:

	void LoadFile(UserInformation *userRanking);
	void SaveFile(string userName, int iScore);

	void PrintScoreBoard(void);
	void SortRanking(UserInformation *Ranking,int iMaxRankingCount);
	void OverwriteScore(string &userName, int &iScore);

	ScoreBoard();
	~ScoreBoard();
};

