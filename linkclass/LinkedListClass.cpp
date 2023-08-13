#include "LinkedListNode.h"


LinkedListNode::LinkedListNode(int value, LinkedListNode* prev, LinkedListNode* Next)
	: id(value),
	  previous(prev),
	  next(Next)

{
	quantity = 0;
	desc = "N/A";
}

LinkedListNode::LinkedListNode(int id, int quantity, std::string desc, LinkedListNode* previous, LinkedListNode* next)
	: id(id),
	quantity(quantity),
	desc(desc),
	previous(previous),
	next(next)
{
}


