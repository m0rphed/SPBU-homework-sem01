#pragma once

#include <iostream>

typedef int ListValueType;

struct ListNode
{
	ListValueType data;
	ListNode *previous;
	ListNode *next;
	
	ListNode(const ListValueType &value, ListNode *pointerPrevious, ListNode *pointerNext);
	
	ListNode();
};


class DoublyLinkedList
{
	ListNode *head;
	ListNode *tail;
	int length;

public:
	DoublyLinkedList();

	~DoublyLinkedList();

	void destroyList();
	
	ListNode *getNodeAt(const int &position);
	
	ListNode *getHead();
	
	ListNode *getTail();
	
	int getLength();
	
	void addTo(const int &position, const ListValueType &value);
	
	void addToEnd(const ListValueType &value);;
	
	void removeFrom(const int &position);
	
	void print();
	
	void printReverse();
};

