#include <string>

class LinkedListNode {
public:
	LinkedListNode(int value,
		LinkedListNode* previous = nullptr,
		LinkedListNode* next = nullptr);

	LinkedListNode(int id, int quantity, std::string desc, LinkedListNode* previous = nullptr,
		LinkedListNode* next = nullptr);

	int id;
	int quantity;
	std::string desc;

	LinkedListNode* previous;
	LinkedListNode* next;
};