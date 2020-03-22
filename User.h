#pragma once

#include <string>

using namespace std;

struct UserInformation
{
	int iScore = 0;
	int iLife;
	int iStage = 0;
	string userName = "기록없음";
};

class User
{
private:
	static User* userInstance;
	UserInformation *newUser = new UserInformation;


public:
	UserInformation* ReturnUserInfo();
	static User* GetUserInformation();

	void Init(void);
	void InputUserName(void);
};

