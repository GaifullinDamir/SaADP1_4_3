#include <iostream>
#include "MainList.h"
#include "Sublist.h"

void init(MainList*& pHeadMain)
{
	pHeadMain->nextMain = nullptr;
	pHeadMain->firstSub = nullptr;
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

