#include "LinkedList.h"

LinkedList::LinkedList()
	: Head(nullptr)
{
	
}

LinkedList::~LinkedList()
{
	outputFile();
	Clear();
}

void LinkedList::Clear()
{
	LinkedListNode* Current = Head;
	while (Current != nullptr)
	{
		LinkedListNode* Temp = Current->next;
		delete Current;
		Current = Temp;
	}
	Head = nullptr;
}

void LinkedList::PushBack(int value)
{
	//Empty Case
	if (Head == nullptr) {
		Head = new LinkedListNode(value);
	}
	// Non-empty
	else {
		LinkedListNode* Current = Head;
		while (Current->next != nullptr) {
			Current = Current->next;
		}
		LinkedListNode* Temp = new LinkedListNode(value, Current);
		Current->next = Temp;

	}
}

void LinkedList::pushNode(int ID, int quan, std::string d)
{
	LinkedListNode* Current = Head;

	if (Head == nullptr)
	{
		Head = new LinkedListNode(ID, quan, d);
	}
	else
	{
		LinkedListNode* Current = Head;
		while (Current->next != nullptr)
		{
			Current = Current->next;
		}
		LinkedListNode* Temp = new LinkedListNode(ID, quan, d, Current);
		Current->next = Temp;

	}
}

void LinkedList::popBack()
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to pop empty linked list");
	}

	if (Head->next == nullptr)
	{
		// size one case
		delete Head;
		Head = nullptr;
	}
	else
	{
		// size 2 or more case
		LinkedListNode* Current = Head;
		while (Current->next != nullptr)
		{
			Current = Current->next;
		}
		Current->previous->next = nullptr;
		delete Current;
	}
}

void LinkedList::popPosition(int ID)
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to pop empty linked list");
	}
	
	else
	{
		LinkedListNode* Current = Head;
		while (Current != nullptr  && Current->id != ID)
		{
			Current = Current->next;
		}

		if (Current == nullptr)
		{
			// ID Not Found
			return;
		}
		
		if (Current->previous == nullptr)
		{
			// ID Found at head
			Head = Current->next;
		}
		// Link nodes
		else
		{	
			Current->previous->next = Current->next;
		}
		// is node at the end?
		if (Current->next != nullptr) 
		{
			Current->next->previous = Current->previous;
		}
	
		delete Current;
		
	}

}

double LinkedList::front()
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call front() on empty linked list");
	}
	return Head->id;
}

double LinkedList::back()
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call back() on empty linked list");
	}

	LinkedListNode* Current = Head;
	
	while (Current->next != nullptr)
	{
		
		Current = Current->next;
	}
	return Current->id;
}

int LinkedList::returnQuantity(int id)
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call returnQuantity() on empty linked list");
	}

	LinkedListNode* Current = Head;

	while (Current != nullptr)
	{
		if (Current->id == id)
		{
			return Current->quantity;
		}
		else
		{
			Current = Current->next;
		}
	}
	if (Current == nullptr) throw std::out_of_range("ID does not exist.");
}

std::string LinkedList::returnDesc(int id)
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call returnDesc() on empty linked list");
	}

	LinkedListNode* Current = Head;

	while (Current != nullptr)
	{
		if (Current->id == id)
		{
			return Current->desc;
		}
		else
		{
			Current = Current->next;
		}
	}
	if (Current == nullptr) throw std::out_of_range("ID does not exist.");
}

void LinkedList::changeID(int oldId, int newId)
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call getID() on empty linked list");
	}

	LinkedListNode* Current = Head;

	while (Current != nullptr && Current->id != oldId)
	{
		Current = Current->next;
	}
	if (Current == nullptr)
	{
		// didn't find id
		return;
	}
	else
	{
		Current->id = newId;
	}
}

void LinkedList::changeQuantity(int id, int newQuantity)
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call changeQuantity() on empty linked list");
	}

	LinkedListNode* Current = Head;

	while (Current != nullptr && Current->id != id)
	{
		Current = Current->next;
	}
	if (Current == nullptr)
	{
		// didn't find id
		return;
	}
	else
	{
		Current->quantity = newQuantity;
	}
}

void LinkedList::changeDesc(int id, std::string newDesc)
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call getID() on empty linked list");
	}

	LinkedListNode* Current = Head;

	while (Current != nullptr && Current->id != id)
	{
		Current = Current->next;
	}
	if (Current == nullptr)
	{
		// didn't find id
		return;
	}
	else
	{
		Current->desc = newDesc;
	}
}

void LinkedList::printNode(int id)
{
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call printNode() on empty linked list");
	}
	LinkedListNode* Current = Head;
	while (Current != nullptr && Current->id != id)
	{
		Current = Current->next;
	}

	if (Current == nullptr)
	{
		std::cout << "ID does not exist" << std::endl;
	}
	else
	{
		std::cout << "________________________________\n\n\tID: " << Current->id << "\n\tQuantity: " << Current->quantity
			<< "\n\tDesc: " << Current->desc << "\t\n________________________________" << std::endl;
	}
}

void LinkedList::outputFile()
{
	std::ofstream file("InvenFile.txt");
	LinkedListNode* Current = Head;

	while (Current != nullptr)
	{
		file << Current->id << std::endl << Current->quantity <<
			std::endl << Current->desc << std::endl;
		Current = Current->next;
	}

	file.close();
}

void LinkedList::inputFile(const std::string& filename)
{
	std::ifstream file(filename);

	int id, quantity;
	std::string desc;

	while (file >> id >> quantity >> desc)
	{
		pushNode(id, quantity, desc);
	}
}





bool LinkedList::empty()
{
	return Head == nullptr;
}

bool LinkedList::IDAlreadyExist(int value)
{
	
	if (Head == nullptr)
	{
		//empty list
		throw std::out_of_range("Tried to call IDAlreadyExist() on empty linked list");
	}

	LinkedListNode* Current = Head;

	while (Current != nullptr) {
		if (Current->id == value)
		{
			// ID already exists

			return true;
		}
		else
		{
			Current = Current->next;
		}
		
	}
	// ID does not exist
	return false;

}

std::ostream& operator<<(std::ostream& ostr, const LinkedList& rhs)
{
	
	LinkedListNode* Current = rhs.Head;
	while (Current != nullptr) {
		ostr << Current->id << std::endl << Current->quantity << std::endl << Current->desc << std::endl << std::endl;
		Current = Current->next;
	}
	
	return ostr;
}

std::istream& operator>>(std::istream& in, LinkedList& list)
{
	std::cout << "Enter id: ";
	int inputId;
	std::cin >> inputId;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout << "Enter a number only" << std::endl;
	}
	else
	{
		if (list.Head == nullptr)
		{
			list.PushBack(inputId);
		}
		else
		{

			if (list.IDAlreadyExist(inputId))
			{
				std::cout << "ID already exists." << std::endl;

			}
			else
			{
				list.PushBack(inputId);
			}

		}
	}
}
