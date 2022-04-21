#include "UserInterface.h"
#include <iostream>
#include <string>
#include "MainList.h"
#include "Sublist.h"

void printMainMenu()
{
	std::cout << std::endl;
	std::cout << "1. Add new list." << std::endl;
	std::cout << "2. Add item to list." << std::endl;
	std::cout << "3. Delete List." << std::endl;
	std::cout << "4. Delete item." << std::endl;
	std::cout << "5. Display list of lists on screen." << std::endl;
	std::cout << "6. Exit." << std::endl;
	std::cout << std::endl;
}

void printAddMenu()
{
	std::cout << std::endl;
	std::cout << "1. Insert before specified - (1)." << std::endl;
	std::cout << "2. Insert after specified - (2)." << std::endl;
	std::cout << std::endl;
}

int userInput()
{
	int option = 0;
	bool check = true;
	std::string optionInput;
	while (check)
	{
		try
		{
			std::cout << "   Enter a number, please: ";
			std::cin >> optionInput;
			option = std::stoi(optionInput);
			check = false;
		}
		catch (const std::exception&)
		{
			std::cout << "   Please enter a number!" << std::endl;
			std::cout << std::endl;
			check = true;
		}
	}
	return option;
}

void workWithUser(MainList*& pHeadMain)
{
	bool work = true;
	while (work)
	{
		printMainMenu();
		std::cout << "   What do you want to do? " << std::endl;
		std::cout << std::endl;
		int option = userInput();
		switch (option)
		{
		case(AddList):
		{
			caseAddList(pHeadMain);
			break;
		}
		case(AddItem):
		{
		
			break;
		}
		case(DeleteList):
		{

			break;
		}
		case(DeleteItem):
		{
	
			break;
		}
		case(Show):
		{
			
			break;
		}
		case(Exit):
		{
			work = false;
			break;
		}
		default:
			std::cout << "   There is no such menu item." << std::endl;
			break;
		}
	}
}

void caseAddList(MainList*& pHeadMain)
{
	MainList* pCurrentMain;
	MainList* pPreviousMain;
	
	if (mainIsEmpty(pHeadMain))
	{
		mainAddAfter(pHeadMain, pCurrentMain);
		std::cout << std::endl;
		std::cout << "   List " << pCurrentMain->sublistNumb <<" added." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		showListNumbers(pHeadMain);

		std::cout << "   Enter an list instead of or after which to insert a new one." << std::endl;
		int currentList = userInput();
		bool check = true;
		check = mainSearch(pHeadMain, pPreviousMain, pCurrentMain, currentList);
		if (check)
		{
			printAddMenu();
			int beforeOrAfter = userInput();

			switch (beforeOrAfter)
			{
				case(Before):
				{
					mainAddBefore(pHeadMain, pPreviousMain, pCurrentMain);
					break;
				}
				case(After):
				{
					mainAddAfter(pHeadMain, pCurrentMain);
					break;
				}
				default:
					std::cout << "   There is no such menu item." << std::endl;
					break;
			}
			std::cout << std::endl;
			std::cout << "   List added." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "   There is no such list." << std::endl;
		}
	}
}

void caseAddItem(MainList*& pHeadMain)
{
	MainList* pPreviousMain;
	MainList* pCurrentMain;
	showListNumbers(pHeadMain);
	std::cout << "   Enter the number of the list to which you want to add the item." << std::endl;
	int currentList = userInput();
	bool check1 = true;
	check1 = mainSearch(pHeadMain, pPreviousMain, pCurrentMain, currentList);

	if (check1)
	{
		Sublist* pHeadSub;
		Sublist* pPreviousSub;
		Sublist* pCurrentSub;

		if (subIsEmpty(pCurrentMain->firstSub))
		{
			std::cout << "   Enter the item to add." << std::endl;
			int data = userInput();
			subAddAfter(pCurrentMain->firstSub, pCurrentSub, data);
			std::cout << std::endl;
			std::cout << "   Item added." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			
			std::cout << "   Enter the element before/after which you want to insert a new one.." << std::endl;
			int searchedData = userInput();
			bool check2 = search(pHeadMain, pHeadSub, pPreviousSub, pCurrentSub, searchedData);

			if (check2)
			{
				printAddMenu();
				int beforeOrAfter = userInput();
				std::cout << "   Enter the item to add." << std::endl;
				int data = userInput();

				switch (beforeOrAfter)
				{
					case(Before):
					{
						subAddBefore(pHeadSub, pPreviousSub, pCurrentSub, data);
						break;
					}
					case(After):
					{
						subAddAfter(pHeadSub, pCurrentSub, data);
						break;
					}
					default:
						std::cout << "   There is no such menu item." << std::endl;
						break;
				}
				std::cout << std::endl;
				std::cout << "   Item added." << std::endl;
				std::cout << std::endl;
			}
			else
			{
				std::cout << "   There is no such element." << std::endl;
			}
		}
	}
	else
	{
		std::cout << "   There is no such list." << std::endl;
	}
	
}

void caseDeleteItem(DoublyList*& pHead)
{
	if (isEmpty(pHead))
	{
		std::cout << "   Nothing to delete." << std::endl;
	}
	std::cout << "   Enter the item to delete." << std::endl;
	int currentData = userInput();
	DoublyList* pCurrent = new DoublyList;
	bool check = true;
	printSearchMenu();
	switch (userInput())
	{
	case(Forward):
		check = searchForward(pHead, pCurrent, currentData);
		break;
	case(Backward):
		check = searchBackward(pHead, pCurrent, currentData);
		break;
	default:
		std::cout << "   There is no such menu item." << std::endl;
		break;
	}
	if (check)
	{
		deleteItem(pCurrent);
		std::cout << std::endl;
		std::cout << "   Item deleted." << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "   There is no such element." << std::endl;
	}
}

void caseShow(DoublyList* pHead)
{
	if (isEmpty(pHead)) { std::cout << "   Nothing to show." << std::endl; }
	else
	{
		printDisplayMenu();
		switch (userInput())
		{
		case(Forward):
			showForward(pHead);
			break;
		case(Backward):
			showBackward(pHead);
			break;
		default:
			std::cout << "   There is no such menu item." << std::endl;
			break;
		}
	}
}