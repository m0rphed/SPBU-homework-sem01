#pragma once

#include <string>
#include <utility>

typedef std::string TypeOfValue;

struct Node
{
	TypeOfValue name = "";
	TypeOfValue phone = "";
	Node *previous;
	Node *next;
	
	Node(const TypeOfValue &newName, const TypeOfValue &newPhone, Node *previousNode, Node *nextNode);
	
	Node(const TypeOfValue &newName, const TypeOfValue &newPhone);
	
	Node();
};


class DoublyLinkedList
{
private:
	Node *head;
	
	Node *tail;
	
	int length;
	
	void checkPosition(const int &position);

public:
	DoublyLinkedList();
	
	~DoublyLinkedList();
	
	void destroyList();
	
	Node *getNodeAt(const int &position);
	
	Node *getHead();
	
	Node *getTail();
	
	int getLength();
	
	// copy array from arg_1 to arg_2 - 1

	DoublyLinkedList *getSubList(const int &beginning, const int &theEnd);
	
	void resetNode(const int &position, Node *newNode);
	
	void resetNodeData(const int &position, const TypeOfValue &username, const TypeOfValue &phone);
	
	void insertTo(const int &position, const TypeOfValue &username, const TypeOfValue &phone);
	
	void append(const TypeOfValue &username, const TypeOfValue &phone);
	
	void remove(const int &position);
	
	void print();
};
