#include <iostream>
#include "Sublist.h"
#include "MainList.h"

void subInit(Sublist*& pHeadSub)
{
	pHeadSub = nullptr;
}
bool subIsEmpty(Sublist* pHeadSub)
{
	return (pHeadSub == nullptr);
}

bool subSearch(Sublist*& pPreviousSub, Sublist*& pCurrentSub, int searchedData)
{
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
}

void subAddBefore(Sublist* pHeadSub, Sublist*& pPreviousSub, Sublist*& pCurrentSub, int data)
{
	if (!subIsEmpty(pHeadSub))
	{
		Sublist* pAdded = new Sublist;
		pAdded->data = data;
		pAdded->nextSub = pCurrentSub;
		pPreviousSub->nextSub = pAdded;
	}
	else { std::cout << "   List is empty." << std::endl; }
}

void subAddAfter(Sublist* pHeadSub, Sublist*& pCurrentSub, int data)
{
	if (!subIsEmpty(pHeadSub))
	{
		Sublist* pAdded = new Sublist;
		pAdded->data = data;
		pAdded->nextSub = pCurrentSub->nextSub;
		pCurrentSub->nextSub = pAdded;
	}
	else
	{
		Sublist* pAdded = new Sublist;
		pAdded->data = data;
		pAdded->nextSub = nullptr;
		pHeadSub = pAdded;
	}
}

void deleteItem()
{

}