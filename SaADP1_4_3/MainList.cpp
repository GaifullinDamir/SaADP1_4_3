#include <iostream>
#include "MainList.h"
#include "Sublist.h"

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
	bool check;
	if (mainIsEmpty(pHeadMain)) 
	{
		std::cout << "   Main list is empty. Nothing to search." << std::endl; 
		return false;
	}
	else
	{
		MainList* pCurrentMain = pHeadMain->nextMain;
		while (pCurrentMain != nullptr)
		{
			pPreviousSub = nullptr;
			pCurrentSub = pCurrentMain->firstSub;
			check = subSearch(pPreviousSub, pCurrentSub, searchedData);
			if (check == true) { return true; }
			pCurrentMain = pCurrentMain->nextMain;
			
		}
		if (pCurrentMain == nullptr)
		{
			std::cout << "   Element not found." << std::endl;
			return false;
		}
	}
}

bool mainSearch(MainList* pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain, int searchedSubList)
{
	pPreviousMain = pHeadMain;
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
	MainList* pAdded = new MainList;
	subInit(pAdded->firstSub);
	if (!mainIsEmpty(pHeadMain))
	{
		pAdded->sublistNumb = g_index;
		pAdded->nextMain = pCurrentMain->nextMain;
		pCurrentMain->nextMain = pAdded;
	}
	else
	{
		pAdded->sublistNumb = g_index;
		pHeadMain->nextMain = pAdded;
		pAdded->nextMain = nullptr;
	}
	::g_index++;
}

void subDelete(MainList*& pHeadMain, MainList*& pPreviousMain, MainList*& pCurrentMain)
{
	if (pPreviousMain == pHeadMain)
	{
		pHeadMain->nextMain = pCurrentMain->nextMain;
	}
	else
	{
		pPreviousMain->nextMain = pCurrentMain->nextMain;
	}
}