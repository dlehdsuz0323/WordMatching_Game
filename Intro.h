#pragma once

#include <vector>
#include <string>

using namespace std;

class Intro
{
private:

	vector<string> vecIntro;
	char cBuffer[256];
	int iIntroSkip = 0;

public:

	void LoadIntroTextFile(vector<string> &loadVecIntro);
	void IntroPrint();
	void PrintIntro();

	Intro();
	~Intro();
};

