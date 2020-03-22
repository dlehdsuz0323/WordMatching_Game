#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "InputWord.h"
#include "Initialize.h"
#include "Utility.h"
#include "WordManager.h"

using namespace std;

InputWord::InputWord()
{
}

//		kbhit()
char* InputWord::Checktheword(void)
{
	cInputWord[index] = getch();

	if (cInputWord[index] == ENTER)
	{
		cInputWord[index] = NULL;
		InputWordErase(index, ENTER);
		index = 0;

		Utility::GetUtility()->gotoxy((MAPWIDTH / 2) + 2, MAPHIGH - 5);
		return cInputWord;
	}

	else if (cInputWord[index] == BACKSPACE)
	{
		if (index != 0)
		{
			index -= 1;
			InputWordErase(index, BACKSPACE);
		}
	}

	else
	{
		Utility::GetUtility()->gotoxy((MAPWIDTH / 2) + index, MAPHIGH - 5);
		cout << cInputWord[index];
		if (index < 11)
		{
			index++;
		}
	}
	return inputEmpty;
}

void InputWord::InputWordErase(int index, int inputkey)
{
	if (inputkey == ENTER)
	{
		for (int i = 0; i < index; i++)
		{
			Utility::GetUtility()->gotoxy((MAPWIDTH / 2) + i, 35);
			cout << " ";
		}
	}

	else if (inputkey == BACKSPACE)
	{
			Utility::GetUtility()->gotoxy((MAPWIDTH / 2) + index, 35);
			cout << " ";
	}
}

InputWord::~InputWord()
{
}
