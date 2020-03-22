#pragma once

#include <string>
#include <vector>

using namespace std;

#define MAXWORDCOUNT 100

enum ITEM
{
	ITEMFALSE,
	ITEMTRUE
};

struct WordInformation
{
	int x;
	int y = 3;
	string strWord;
	bool bWordAlive;
	bool bItemWord;
};

class WordManager
{
private:

	string strWord;
	vector<string> vectorWord;

	int iNumberWordStructures = 0;
	int iNewLineCount = 0;
	int iWordArr = 0;
	int iRegeneration = 0;
	int iCheckRegeneration = 0;
	int iItemCount = 20;
	char chWord[256] = { 0 };

	int iCheckCounter = 0;

	int iRandomWidthVariableArray[MAXWORDCOUNT] = { 0 };
	int iRandomNewLineVariableArray[MAXWORDCOUNT] = { 0 };
	int iRandomItemVariableArray[MAXWORDCOUNT] = { 0 };

public:
	void LoadFileTheWord(struct WordInformation wordInfor[MAXWORDCOUNT]);
	void RegenerationWord(struct WordInformation *wordInfor,int &iWordArr);
	void CheckRegenerationWord(struct WordInformation wordInfor[MAXWORDCOUNT], int &iWordArr);
	void ReceivesRandomNumber(void);


	WordManager();
	~WordManager();
};