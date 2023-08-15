
#include "LinkedListNode.h"
#include <iostream>
#include <istream>
#include <fstream>
class LinkedList {
public:
	LinkedList();
	~LinkedList();

	void Clear();
	void PushBack(int value);
	void popBack();
	void popPosition(int ID);
	void changeID(int oldId, int newId);
	void changeQuantity(int id, int newQuantity);
	void changeDesc(int id, std::string newDesc);
	void printNode(int id);
	void outputFile();
	void inputFile(const std::string& filename);
	void pushNode(int ID, int quan, std::string d);
	
	friend std::ostream& operator <<(std::ostream& ostr,  const LinkedList& rhs);
	friend std::istream& operator >>(std::istream& in, LinkedList& list);
	
	double front();
	double back();

	int returnQuantity(int id);

	std::string returnDesc(int id);
	
	bool empty();
	bool IDAlreadyExist(int value);


private:
	LinkedListNode* Head;
};
///