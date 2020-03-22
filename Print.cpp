#include <iostream>
#include <Windows.h>

#include "Print.h"
#include "LIFE.h"
#include "Utility.h"

using namespace std;

Print::Print()
{
	Initialize InitializeMap;
	InitializeMap.InitializeGameMap(iMap);
}

void Print::PrintMap(void)
{
	for (int y = 0; y < MAPHIGH; y++)
	{
		for (int x = 0; x < MAPWIDTH; x++)
		{
			if (iMap[y][x] == EMPTY)
			{
				cout << "  ";
			}
			else if (iMap[y][x] == UWALL)
			{
				cout << "¦¡";
			}
			 else if (iMap[y][x] == DWALL)
			 {
				 cout << "¦¡";
			 }
			 else if (iMap[y][x] == LIFE_AVLIVE)
			 {
				 cout << "¢¾";
			 }
			 else if (iMap[y][x] == LIFE_LOSE)
			 {
				 cout << "¢½";
			 }
		 }	
		cout << endl;
	}
}

Print::~Print()
{
}
