#include <iostream>
#include <Windows.h>

#include "User.h"
#include "Initialize.h"
#include "Utility.h"

using namespace std;

User* User::userInstance = nullptr;

User* User::GetUserInformation()
{
	if (userInstance == nullptr)
	{
		userInstance = new User();
	}
	return userInstance;
}

UserInformation* User::ReturnUserInfo()
{	
	return newUser;
}

void User::InputUserName(void)
{
	Utility::GetUtility()->gotoxy(MAPWIDTH / 2, MAPHIGH / 2);
	cout << "이름 입력:  ";
	cin >> newUser->userName;
	cout << newUser->userName;

	system("cls");
}

void User::Init(void)
{
	newUser->iLife = 15;
	newUser->iScore = 0;
	newUser->iStage = 0;
}
