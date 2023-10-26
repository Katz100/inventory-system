
#include "LinkedListNode.h"
#include <iostream>
#include <istream>
#include <fstream>
class LinkedList {
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& other); // copy contructor

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
	void printNeighbors(int ID);
	void swap(int id1, int id2);
	void sort();

	friend std::ostream& operator <<(std::ostream& ostr,  const LinkedList& rhs);
	friend std::istream& operator >>(std::istream& in, LinkedList& list);
	int operator[](int num);

	double front();
	double back();

	int getId(int num);
	int returnQuantity(int id);
	int size();

	std::string returnDesc(int id);
	
	bool empty();
	bool IDAlreadyExist(int value);


private:
	LinkedListNode* Head;
};
///