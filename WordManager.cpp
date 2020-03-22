#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>

#include "Utility.h"
#include "WordManager.h"
#include "Initialize.h"

using namespace std;

WordManager::WordManager()
{
}

void WordManager::ReceivesRandomNumber(void)
{
	srand(time(NULL));

	for (int i = 0; i < MAXWORDCOUNT; i++)
	{
		iRandomNewLineVariableArray[i] = rand() % 98;
		iRandomWidthVariableArray[i] = rand() % (MAPWIDTH - 2);
	
		iRandomItemVariableArray[i] = rand() % 2;
	}
}

void WordManager::LoadFileTheWord(struct WordInformation wordInfor[MAXWORDCOUNT])
{
	FILE *loadWordTextFile = fopen("word.txt", "r");
	vectorWord.clear();
	iNewLineCount = 0;
	iNumberWordStructures = 0;

	ReceivesRandomNumber();

	while (true)
	{
		fseek(loadWordTextFile, 0, SEEK_SET);

		// 파일에서 랜덤숫자만큼 개행 후 단어 받아옴
		for (int i = 0; i < iRandomNewLineVariableArray[iNewLineCount]; i++)
		{
			fscanf(loadWordTextFile, "%s\n", &chWord);
		}

		strWord = chWord;
		vectorWord.push_back(strWord.c_str());
		iNewLineCount++;


		if (iNewLineCount == MAXWORDCOUNT)
		{
			break;
		}

	}

	//단어 구조체 초기화
	for (auto iter = vectorWord.begin(); iter != vectorWord.end(); iter++)
	{
		wordInfor[iNumberWordStructures].x =iRandomWidthVariableArray[iNumberWordStructures];
		wordInfor[iNumberWordStructures].y = 3;
		wordInfor[iNumberWordStructures].strWord = (*iter);
		wordInfor[iNumberWordStructures].bWordAlive = false;
		wordInfor[iNumberWordStructures].bItemWord = iRandomItemVariableArray[iNumberWordStructures];

		iNumberWordStructures++;
	}

	fclose(loadWordTextFile);
}


void WordManager::RegenerationWord(struct WordInformation *wordInfor, int &iWordArr)
{
		vectorWord.clear();
		LoadFileTheWord(wordInfor);
		wordInfor[0].bWordAlive = true;
		iWordArr = 0;

		iRegeneration = 0;
		iCheckRegeneration = 0;
		iNumberWordStructures = 0;

}

void WordManager::CheckRegenerationWord(struct WordInformation wordInfor[MAXWORDCOUNT], int &iWordArr)
{
		for (int i = 0; i < MAXWORDCOUNT; i++)
		{
			if (wordInfor[i].bWordAlive == false)
			{
				wordInfor[i].bWordAlive = true;
				wordInfor[i].y = 3;
				iRegeneration++;
			}

			if (iRegeneration == MAXWORDCOUNT)
			{
				iWordArr = 0;
			}
		}
}

WordManager::~WordManager()
{
}