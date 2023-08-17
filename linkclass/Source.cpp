#include <iostream>
#include "LinkedList.h"



void menu();
int getID();
int getInput();

LinkedList Inventory;
int running = 1;

int main() 
{
	
	Inventory.inputFile("InvenFile.txt");

	
	while (running == 1) 
	{	
		menu();
	}
	
	
	return 0;
}

void menu() {
	std::cout << "------------------MAIN MENU--------------------" << std::endl;
	

	std::cout << "1. Create Inventory\n" <<
		"2. Print All Inventory Items.\n" <<
		"3. Print Specific Inventory Item\n" <<
		"4. Print Neighbor\n" <<
		"5. Delete Inventory Item\n" <<
		"6. Clear Inventory\n" <<
		"7. Change ID\n" <<
		"8. Change Quantity\n" <<
		"9. Change Description\n" <<
		"10. Quit\n\n";
	
	int UserInput = getInput();
	std::string s;
	
	if (UserInput == -1) {
		//catch error
		return;
	}

	try {
		if (UserInput == 1)
		{
			std::cin >> Inventory;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), \
				'\n');
		}
		else if (UserInput == 2)
		{
			std::cout << Inventory;
		}
		else if (UserInput == 3)
		{
			int id = getID();
			if (id == -1)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			else
			{
				Inventory.printNode(id);
			}
		}
		else if (UserInput == 4)
		{
			int id = getID();
			if (id == -1)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			else
			{
				Inventory.printNeighbors(id);
			}
		}
		else if (UserInput == 5)
		{
			int id = getID();
			if (id == -1)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			else
			{
				Inventory.popPosition(id);
			}
		}
		else if (UserInput == 6)
		{
			Inventory.Clear();
		}
		else if (UserInput == 7)
		{
			int id = getID();
			
			if (id == -1)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			else
			{
				try {
					std::string str;
					std::cout << "Enter new id: ";
					std::getline(std::cin, str);
					int newID = stoi(str);
					Inventory.changeID(id, newID);
				}
				catch (const std::invalid_argument& e)
				{
					// char infront
					std::cout << e.what() << std::endl;
					return;
				}
			}
		}
		else if (UserInput == 8)
		{
			int id = getID();

			if (id == -1)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			else
			{
				try {
					std::string str;
					std::cout << "Enter new quantity: ";
					std::getline(std::cin, str);
					int quan = stoi(str);
					Inventory.changeQuantity(id, quan);
				}
				catch (const std::invalid_argument& e)
				{
					// char infront
					std::cout << e.what() << std::endl;
					return;
				}
			}
		}
		else if (UserInput == 9)
		{
			int id = getID();

			if (id == -1)
			{
				std::cout << "Error" << std::endl;
				return;
			}
			else
			{
				try {
					std::string str;
					std::cout << "Enter new desc: ";
					std::getline(std::cin, str);
					Inventory.changeDesc(id, str);
				}
				catch (const std::invalid_argument& e)
				{
					// char infront
					std::cout << e.what() << std::endl;
					return;
				}
			}
		}
		else if (UserInput == 10)
		{
			running = 2;
		}
		else
		{
			std::cout << "Input not valid" << std::endl;
		}
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

int getID()
{
	try {
		std::string str;
		std::cout << "Enter ID: ";
		std::getline(std::cin, str);
		int id = stoi(str);
		return id;
	}
	catch (const std::invalid_argument& e)
	{
		// char infront
		std::cout << e.what() << std::endl;
		return -1;
	}
}

int getInput()
{
	try {
		std::string str;
		std::cout << "Enter option: ";
		std::getline(std::cin, str);
		int id = stoi(str);
		return id;
	}
	catch (const std::invalid_argument& e)
	{
		// char infront
		std::cout << e.what() << std::endl;
		return -1;
	}
}


