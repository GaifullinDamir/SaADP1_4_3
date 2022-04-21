#pragma once
#include "Sublist.h"

int g_index = 1;

struct MainList
{
	int sublistNumb;
	MainList* nextMain;
	Sublist* firstSub;
};

void mainInit(MainList*& pHeadMain);

bool search(MainList* pHeadMain, Sublist*& pPreviousSub, Sublist*& pCurrentSub, int searchedData);

bool searchMain(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain, int searchedSubList);

void mainAddBefore(MainList* pHeadMain, MainList*& pPreviousMain,  MainList*& pCurrentMain);

void mainAddAfter(MainList* pHeadMain, MainList*& pCurrentMain);

void deleteSublist(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain);