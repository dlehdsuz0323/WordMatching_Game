#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "LIFE.h"
#include "Utility.h"
#include "User.h"
#include "ScoreBoard.h"
//int iLife = 15;


LIFE::LIFE()
{
}


bool LIFE::CheckLife(int &iLife)
{
	// 3 floor
	/*if (10 < iLife && iLife <= 15)
	{
		lifeCheck = iLife;
		Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 4);
		lifeCheck %= 10;
		for (int i = 0; i < lifeCheck; i++)
			cout << "¢¾";
		cout << "  ";
	}*/




	if (15 == iLife)
	{
		lifeCheck = iLife;
		Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 4);
		cout << "¢¾¢¾¢¾¢¾¢¾";
	}

	else if (10 < iLife && iLife < 15)
	{
		lifeCheck = iLife;
		Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 4);
		lifeCheck %= 5;
		for (int i = 0; i < lifeCheck; i++)
			cout << "¢¾";
		cout << "  ";
	}

	else
	{
		Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 4);
		cout << "  ";
	}

	// 2 floor
	if (10 <= iLife)
	{
		lifeCheck = iLife;
	Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 3);
		cout << "¢¾¢¾¢¾¢¾¢¾";
	}

	else if (5 < iLife && iLife < 10)
	{
		lifeCheck = iLife;
	Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 3);
	lifeCheck %= 5;
		for (int i = 0; i < lifeCheck; i++)
			cout << "¢¾";
		cout << "  ";
	}

	else
	{
		Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 3);
		cout << "  ";
	}

	 // 1 floor
	 if (5 <= iLife)
	 {
		 lifeCheck = iLife;
	 Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 2);
		 cout << "¢¾¢¾¢¾¢¾¢¾";
	 }

	 else if (0 <= iLife && iLife < 5)
	 {
		 lifeCheck = iLife;
	 Utility::GetUtility()->gotoxy((MAPWIDTH / 2), MAPHIGH - 2);
	 lifeCheck /= 1;
		 for (int i = 0; i < lifeCheck; i++)
			 cout << "¢¾";
		 cout << "  ";
	 }

	 if (User::GetUserInformation()->ReturnUserInfo()->iLife <= 0)
	 {
		 return false;
	 }


	 return true;
}

LIFE::~LIFE()
{
}

