#include <iostream>

#include "LifeIncrease.h"
#include "LIFE.h"
#include "Utility.h"
#include "User.h"

using namespace std;

LifeIncrease::LifeIncrease()
{
}

void LifeIncrease::LifeIncreased(int &iItemLimitCount, int &iItemNumber, bool *iItemAlive)
{
	if (iItemLimitCount == 1)
	{
		if (User::GetUserInformation()->ReturnUserInfo()->iLife < 15)
		{
			Utility::GetUtility()->gotoxy(0, 0);
			cout << "                     ";
			Utility::GetUtility()->gotoxy(0, 0);
			cout << "������ +1 ����";
			User::GetUserInformation()->ReturnUserInfo()->iLife++;
		}

		Utility::GetUtility()->gotoxy(0, 0);
		cout << "                     ";
		Utility::GetUtility()->gotoxy(0, 0);
		cout << "������ �ִ�";

		iItemLimitCount = 0;
		iItemNumber = 0;
		*iItemAlive = false;
	}

	iItemLimitCount++;

}


LifeIncrease::~LifeIncrease()
{
}
