#include <iostream>
#include "MainList.h"
#include "Sublist.h"

int g_index = 1;

void mainInit(MainList*& pHeadMain)
{
	pHeadMain->nextMain = nullptr;
	subInit(pHeadMain->firstSub);

}

bool mainIsEmpty(MainList* pHeadMain)
{
	return (pHeadMain->nextMain == nullptr);
}

void showList(MainList* pHeadMain)
{
	if (!mainIsEmpty(pHeadMain))
	{
		MainList* pCurrentMain = pHeadMain->nextMain;
		while (pCurrentMain != nullptr)
		{
			Sublist* pCurrentSub = pCurrentMain->firstSub;
			std::cout << "   Sublist " << pCurrentMain->sublistNumb << ": ";
			while (pCurrentSub != nullptr)
			{
				std::cout << pCurrentSub->data << " ";
				pCurrentSub = pCurrentSub->nextSub;
			}
			pCurrentMain = pCurrentMain->nextMain;
			std::cout << std::endl;
		}
	}
	else std::cout << "   Main list is empty. Nothing to show." << std::endl;
}

void showListNumbers(MainList*& pHeadMain)
{
	MainList* pCurrentMain = pHeadMain->nextMain;
	std::cout << std::endl;
	std::cout << "   Available list numbers: ";
	while (pCurrentMain != nullptr)
	{
		std::cout << " " << pCurrentMain->sublistNumb << " |";
		pCurrentMain = pCurrentMain->nextMain;
	}
	std::cout << std::endl;
}

bool search(MainList* pHeadMain, MainList*& pCurrentMain, int searchedData)
{
	bool check = true;
	pCurrentMain= pHeadMain->nextMain;
	while (pCurrentMain != nullptr)
	{
		Sublist* pPreviousSub = nullptr;
		Sublist* pCurrentSub = pCurrentMain->firstSub;
		check = subSearch(pPreviousSub, pCurrentSub, searchedData);
		if (check == true)
		{
			std::cout << "   Item: " << searchedData << " in list: " << pCurrentMain->sublistNumb << std::endl;
			return true;
		}
		pCurrentMain = pCurrentMain->nextMain;

	}
	std::cout << "   Item: " << searchedData << " was not found." << std::endl;
	return false;
}

bool mainSearch(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain, int searchedSubList)
{
	pPreviousMain = pHeadMain;
	pCurrentMain = pHeadMain->nextMain;
	while (pCurrentMain != nullptr)
	{
		if (pCurrentMain->sublistNumb == searchedSubList)
		{
			return true;
		}
		pPreviousMain = pCurrentMain;
		pCurrentMain = pCurrentMain->nextMain;
	}
	return false;
}

void mainAddBefore(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain)
{
	if (!mainIsEmpty(pHeadMain))
	{
		MainList* pAdded = new MainList;
		subInit(pAdded->firstSub);
		pAdded->sublistNumb = g_index;
		pAdded->nextMain = pCurrentMain;
		pPreviousMain->nextMain = pAdded;
		::g_index++;
	}
	else { std::cout << "   Main list is empty." << std::endl; }
}

void mainAddAfter(MainList*& pHeadMain, MainList*& pCurrentMain)
{
	if (!mainIsEmpty(pHeadMain))
	{
		MainList* pAdded = new MainList;
		subInit(pAdded->firstSub);
		pAdded->sublistNumb = g_index;
		pAdded->nextMain = pCurrentMain->nextMain;
		pCurrentMain->nextMain = pAdded;
	}
	else
	{
		subInit(pCurrentMain->firstSub);
		pCurrentMain->sublistNumb = g_index;
		pHeadMain->nextMain = pCurrentMain;
		pCurrentMain->nextMain = nullptr;
	}
	::g_index++;
}

void subDelete(MainList*& pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain)
{
	Sublist* pCurrentSub = pCurrentMain->firstSub;
	Sublist* pTemporary;
	while (!subIsEmpty(pCurrentSub))
	{
		pTemporary = pCurrentSub;
		pCurrentSub = pTemporary->nextSub;
		delete pTemporary;
	}
	pCurrentMain->firstSub = nullptr;

	if (pPreviousMain == pHeadMain)
	{
		pHeadMain->nextMain = pCurrentMain->nextMain;
	}
	else
	{
		pPreviousMain->nextMain = pCurrentMain->nextMain;
	}
	delete pCurrentMain;
	pCurrentMain = nullptr;
}

void clearMemory(MainList*& pHeadMain)
{
	MainList*& pPreviousMain = pHeadMain;
	MainList*& pCurrentMain = pHeadMain->nextMain;
	while (!mainIsEmpty(pHeadMain))
	{
		subDelete(pHeadMain, pPreviousMain, pCurrentMain);
		pPreviousMain = pHeadMain;
		pCurrentMain = pHeadMain->nextMain;
	}
	pHeadMain = nullptr;
	pPreviousMain = nullptr;
	pCurrentMain = nullptr;
}