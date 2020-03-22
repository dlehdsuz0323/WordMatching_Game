#pragma once

#include "Initialize.h"

using namespace std;
extern int iSpeed;
extern int iWordSpeed;

class Word
{
private:

	char chWord[128] = { 0 };
	int iWordArr = 0;
	int iItemCount = 0;
	int iWordRegenerationCounter = 0;
	int iStageCount = 0;
	int iScore = 0;
	int iItemLimitCount = 0;
	int iItmeNumber = 0;
	bool iWordNewLine = false;
	bool iItemAlive = false;


public:

	bool Update();

	void LoadTheWord(struct WordInformation wordInfor[MAXWORDCOUNT]);
	void EraseWordInMap(struct WordInformation wordInfor[MAXWORDCOUNT]);
	void OutputWord(struct WordInformation *wordInfor, int &iWordArr);
	void TheWordCrashesOnTheFloor(struct WordInformation wordInfor[MAXWORDCOUNT], int &iLife);
	void CheckInputWord(struct WordInformation wordInfor[MAXWORDCOUNT],char *word);

	Word();
	~Word();
};