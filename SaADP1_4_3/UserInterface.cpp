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
			caseAddItem(pHeadMain);
			break;
		}
		case(DeleteList):
		{
			caseDeleteList(pHeadMain);
			break;
		}
		case(DeleteItem):
		{
			caseDeleteItem(pHeadMain);
			break;
		}
		case(Show):
		{
			caseShow(pHeadMain);
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
	MainList* pCurrentMain = new MainList;
	MainList* pPreviousMain = new MainList;
	
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
	MainList* pPreviousMain /*= new MainList*/;
	MainList* pCurrentMain /*= new MainList*/;
	showListNumbers(pHeadMain);
	std::cout << "   Enter the number of the list to which you want to add the item." << std::endl;
	int currentList = userInput();
	bool check1 = true;
	check1 = mainSearch(pHeadMain, pPreviousMain, pCurrentMain, currentList);

	if (check1)
	{
		Sublist* pHeadSub = new Sublist;
		Sublist* pPreviousSub = new Sublist;
		Sublist* pCurrentSub = new Sublist;

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

void caseDeleteList(MainList*& pHeadMain)
{
	if (mainIsEmpty(pHeadMain))
	{
		std::cout << "   Nothing to delete." << std::endl;
	}
	else
	{
		showListNumbers(pHeadMain);
		std::cout << "   Enter list number to delete." << std::endl;
		int currentList = userInput();
		MainList* pPreviousMain = new MainList;
		MainList* pCurrentMain = new MainList;

		bool check = mainSearch(pHeadMain, pPreviousMain, pCurrentMain, currentList);

		if (check)
		{
			subDelete(pHeadMain, pPreviousMain, pCurrentMain);
			std::cout << std::endl;
			std::cout << "   Sublist deleted." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "   There is no such element." << std::endl;
		}
	}
	
}

void caseDeleteItem(MainList* pHeadMain)
{
	if (mainIsEmpty(pHeadMain))
	{
		std::cout << "   Nothing to delete." << std::endl;
	}
	else
	{
		std::cout << "   Enter the item to delete." << std::endl;
		int searchedData = userInput();
		Sublist* pHeadSub = new Sublist;
		Sublist* pPreviousSub = new Sublist;
		Sublist* pCurrentSub = new Sublist;
		bool check = search(pHeadMain, pHeadSub, pPreviousSub, pCurrentSub, searchedData);
		
		if (check)
		{
			deleteItem(pPreviousSub, pCurrentSub);
			std::cout << std::endl;
			std::cout << "   Item deleted." << std::endl;
			std::cout << std::endl;
		}
		else
		{
			std::cout << "   There is no such element." << std::endl;
		}
	}
	
}

void caseShow(MainList* pHeadMain)
{
	if (mainIsEmpty(pHeadMain)) { std::cout << "   Nothing to show." << std::endl; }
	else{showList(pHeadMain);}
}