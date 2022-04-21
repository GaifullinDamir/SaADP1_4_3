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
void printDisplayMenu();
void printSearchMenu();
int userInput();
void workWithUser(DoublyList*& pHead);
void caseAddItem(DoublyList*& pHead);
void caseDeleteItem(DoublyList*& pHead);
void caseShow(DoublyList* pHead);

