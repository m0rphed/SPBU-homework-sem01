#pragma once

#include <string>

typedef std::string TypeOfValue;

struct myNode
{
	TypeOfValue name = "";
	TypeOfValue phone = "";
	myNode *previous;
	myNode *next;
	
	myNode(const TypeOfValue &newName, const TypeOfValue &newPhone, myNode *pointerToPrevious, myNode *pointerToNext);
	
	myNode(const TypeOfValue &newName, const TypeOfValue &newPhone);
	
	myNode();
};


class DoublyLinkedList
{
private:
	myNode *head;
	myNode *tail;
	int length;

public:
	DoublyLinkedList();
	
	~DoublyLinkedList();
	
	void destroyList();
	
	myNode *getNodeAt(const int &position);
	
	myNode *getHead();
	
	myNode *getTail();
	
	int getLength();
	
	// copy array from arg_1 to arg_2 - 1
	DoublyLinkedList *sliceList(const int &fromPosition, const int &toPosition);
	
	void setNodeAt(const int &index, myNode *newNode);
	
	void addTo(const int &position, const TypeOfValue &username, const TypeOfValue &phone);
	
	void addToEnd(const TypeOfValue &username, const TypeOfValue &phone);
	
	void removeFrom(const int &position);
	
	void print();
};
