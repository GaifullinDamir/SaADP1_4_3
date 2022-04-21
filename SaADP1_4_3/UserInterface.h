#pragma once
#include "MainList.h"
#include "Sublist.h"

enum userInterface
{
	AddList = 1,
	AddItem,
	DeleteList,
	DeleteItem,
	Show,
	Exit,
	Before = 1,
	After = 2,
	Forward = 1,
	Backward = 2,
	Continue = 1,
};

void printMainMenu();

void printAddMenu();

int userInput();

void workWithUser(MainList*& pHeadMain);

void caseAddList(MainList*& pHeadMain);

void caseAddItem(MainList*& pHeadMain);

void caseDeleteList(MainList*& pHeadMain);

void caseDeleteItem(MainList* pHeadMain);

void caseShow(MainList* pHeadMain);

