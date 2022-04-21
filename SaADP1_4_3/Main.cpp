#include <iostream>
#include "MainList.h"
#include "Sublist.h"
#include "UserInterface.h"

int main()
{
	MainList* pHeadMain = new MainList;
	mainInit(pHeadMain);
	workWithUser(pHeadMain);
	clearMemory(pHeadMain);
}