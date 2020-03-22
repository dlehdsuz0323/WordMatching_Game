#include "Nomal.h"
#include "Utility.h"
#include <iostream>

using namespace std;



Nomal::Nomal()
{
}

void Nomal::NomalWord(void)
{
	Utility::GetUtility()->gotoxy(0, 0);
	cout << "                     ";
	Utility::GetUtility()->gotoxy(0, 0);
	cout << "Nomal";
}


Nomal::~Nomal()
{
}
