#pragma once
#include "Sublist.h"



struct MainList
{
	int sublistNumb;
	MainList* nextMain;
	Sublist* firstSub;
};

void mainInit(MainList*& pHeadMain);

bool mainIsEmpty(MainList* pHeadMain);

void showList(MainList* pHeadMain);

void showListNumbers(MainList*& pHeadMain);

bool search(MainList* pHeadMain, Sublist*& pHeadSub, Sublist*& pPreviousSub, Sublist*& pCurrentSub, int searchedData);

bool mainSearch(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain, int searchedSubList);

void mainAddBefore(MainList* pHeadMain, MainList*& pPreviousMain,  MainList*& pCurrentMain);

void mainAddAfter(MainList*& pHeadMain, MainList*& pCurrentMain);

void subDelete(MainList*& pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain);

void clearMemory(MainList*& pHeadMain);