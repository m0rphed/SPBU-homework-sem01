#pragma once

typedef int ElementType;

struct Node
{
	ElementType data;
	Node *previous;
	Node *next;
	
	Node(const ElementType &value, Node *pointerToPrevious, Node *pointerToNext);
	
	Node();
};


class DoublyLinkedList
{
private:
	Node *head;
	Node *tail;
	int length;

public:
	DoublyLinkedList();
	
	~DoublyLinkedList();
	
	void destroyList();
	
	Node *getNodeAt(const int &position);
	
	Node *getHead();
	
	Node *getTail();
	
	int getLength();
	
	void addTo(const int &position, const ElementType &value);
	
	void addToEnd(const ElementType &value);;
	
	void removeFrom(const int &position);
	
	void print();
	
	void printReverse();
};
