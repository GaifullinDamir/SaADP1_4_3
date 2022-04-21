#include <iostream>
#include "MainList.h"
#include "Sublist.h"

void initMain(MainList*& pHeadMain)
{
	pHeadMain->nextMain = nullptr;
	initSub(pHeadMain->firstSub);

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
			std::cout << "   Подсписок №" << pCurrentMain->sublistNumb << ": ";
			while (pCurrentSub != nullptr)
			{
				std::cout << pCurrentSub->data;
				pCurrentSub = pCurrentSub->nextSub;
			}
			pCurrentMain = pCurrentMain->nextMain;
			std::cout << std::endl;
		}
	}
	else std::cout << "   Main list is empty. Nothing to show." << std::endl;
}

bool search(MainList* pHeadMain, Sublist*& pPreviousSub, Sublist*& pCurrentSub, int searchedData)
{
	if (mainIsEmpty(pHeadMain)) { std::cout << "   Main list is empty. Nothing to search." << std::endl; }
	else
	{
		MainList* pCurrentMain = pHeadMain->nextMain;
		while (pCurrentMain != nullptr)
		{
			pPreviousSub = nullptr;
			pCurrentSub = pCurrentMain->firstSub;
			while (pCurrentSub != nullptr)
			{
				if (pCurrentSub->data == searchedData) 
				{
					std::cout << "   Item found." << std::endl;
					return true;
				}
				pPreviousSub = pCurrentSub;
				pCurrentSub = pCurrentSub->nextSub;
			}
			pCurrentMain = pCurrentMain->nextMain;
			if (pCurrentMain == nullptr) 
			{
				std::cout << "   Element not found." << std::endl; 
				return false;
			}
		}
	}
}

bool searchMain(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain, int searchedSubList)
{
	pCurrentMain = pHeadMain->nextMain;
	while (pCurrentMain != nullptr)
	{
		if (pCurrentMain->sublistNumb == searchedSubList)
		{
			std::cout << "   Sublist found." << std::endl;
			return true;
		}
		pPreviousMain = pCurrentMain;
		pCurrentMain = pCurrentMain->nextMain;
	}
	if (pCurrentMain == nullptr)
	{
		std::cout << "   Sublist not found." << std::endl;
		return false;
	}
}

void mainAddBefore(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain)
{
	if (!mainIsEmpty(pHeadMain))
	{
		MainList* pAdded = new MainList;
		initSub(pAdded->firstSub);
		pAdded->sublistNumb = pCurrentMain->sublistNumb;
		pCurrentMain->sublistNumb++;
		pAdded->nextMain = pCurrentMain;
		pPreviousMain->nextMain = pAdded;
	}
	else { std::cout << "   Main list is empty." << std::endl; }
}

void mainAddAfter(MainList*& pHeadMain, MainList*& pCurrentMain)
{
	MainList* pAdded = new MainList;
	initSub(pAdded->firstSub);
	if (!mainIsEmpty(pHeadMain))
	{
		pAdded->sublistNumb = pCurrentMain->nextMain->sublistNumb;
		pCurrentMain->nextMain->sublistNumb++;
		pAdded->nextMain = pCurrentMain->nextMain;
		pCurrentMain->nextMain = pAdded;
	}
	else
	{
		pAdded->sublistNumb = 1;
		pHeadMain->nextMain = pAdded;
		pAdded->nextMain = nullptr;
	}
}