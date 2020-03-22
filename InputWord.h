#pragma once

enum KEYBOARD
{
	BACKSPACE = 8,
	ENTER = 13,
	SPACEBAR = 32
};

class InputWord
{

private:
	char cInputWord[20];
	char inputEmpty[128];
	int  index = 0;
public:

	char* Checktheword(void);
	void InputWordErase(int index, int inputkey);

	InputWord();
	~InputWord();
};

