#include <iostream>
#include "LinkedList.h"




void menu();

LinkedList Inventory;
int running = 1;

int main() {
	Inventory.inputFile("InvenFile.txt");

	while (running == 1) {
		menu();
	}
	return 0;
}

void menu() {
	std::cout << "------------------MAIN MENU--------------------" << std::endl;
	int UserInput;

	std::cout << "1. Create Inventory\n2. Print All Inventory Items.\n3. Print Specific Inventory Item" <<
		"\n4. Delete Inventory Item\n5. Clear Inventory\n6. Change ID\n7. Change Quantity\n8. Change Description\n9. Quit\n\n>>> ";

	try {
		std::cin >> UserInput;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid Choice" << std::endl;
			return;
		}
		if (UserInput == 1)
		{
			Inventory.inputIventory();
		}
		if (UserInput == 2)
		{
			std::cout << Inventory;
		}
		if (UserInput == 3)
		{
			int InputID;
			std::cout << "Enter ID: ";
			std::cin >> InputID;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid Choice" << std::endl;
				return;
			}
			else
			{
				Inventory.printNode(InputID);
			}
		}
		if (UserInput == 4)
		{
			int InputID;
			std::cout << "Enter ID: ";
			std::cin >> InputID;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid Choice" << std::endl;
				return;
			}
			else
			{
				Inventory.popPosition(InputID);
			}
		}
		if (UserInput == 5)
		{
			Inventory.Clear();
		}
		if (UserInput == 6)
		{
			int InputID;
			std::cout << "Enter ID: ";
			std::cin >> InputID;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid Choice" << std::endl;
				return;
			}
			else
			{
				int newID;
				std::cout << "Enter new ID: ";
				std::cin >> newID;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid Choice" << std::endl;
					return;
				}
				else
				{
					Inventory.changeID(InputID, newID);
				}
			}
		}
		if (UserInput == 7)
		{
			int InputID;
			std::cout << "Enter ID: ";
			std::cin >> InputID;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid Choice" << std::endl;
				return;
			}
			else
			{
				int newID;
				std::cout << "Enter new Quantity: ";
				std::cin >> newID;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid Choice" << std::endl;
					return;
				}
				else
				{
					Inventory.changeQuantity(InputID, newID);
				}
			}
		}
		if (UserInput == 8)
		{
			int InputID;
			std::cout << "Enter ID: ";
			std::cin >> InputID;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Invalid Choice" << std::endl;
				return;
			}
			else
			{
				std::string desc;
				std::cout << "Enter new Description: ";
				std::cin >> desc;
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid Choice" << std::endl;
					return;
				}
				else
				{
					Inventory.changeDesc(InputID, desc);
				}
			}
		}
		if (UserInput == 9)
		{
			running = 2;
		}
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
}




