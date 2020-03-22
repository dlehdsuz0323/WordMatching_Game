#pragma once

//extern int iScore;

class Score
{
private:
	int iStageCount = 0;
public:

	void PrintScore(int &iScore);
	void Stage(int &iScore, int &iStageCount);

	Score();
	~Score();
};

