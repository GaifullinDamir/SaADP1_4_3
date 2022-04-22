#pragma once
struct Sublist
{
	int data;
	Sublist* nextSub;
};

void subInit(Sublist*& pHeadSub);

bool subIsEmpty(Sublist* pHeadSub);

bool subSearch(Sublist*& pPreviousSub, Sublist*& pCurrentSub, int searchedData);

void subAddBefore(Sublist* pHeadSub, Sublist*& pPreviousSub, Sublist*& pCurrentSub, int data);

void subAddAfter(Sublist*& pHeadSub, Sublist*& pCurrentSub, int data);

void deleteItem(Sublist*& pPreviousSub, Sublist*& pCurrentSub);