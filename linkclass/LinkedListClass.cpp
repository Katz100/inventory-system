#include "LinkedListNode.h"


LinkedListNode::LinkedListNode(int value, LinkedListNode* prev, LinkedListNode* Next)
	: id(value),
	  previous(prev),
	  next(Next)

{
	quantity = 0;
	desc = "N/A";
}


