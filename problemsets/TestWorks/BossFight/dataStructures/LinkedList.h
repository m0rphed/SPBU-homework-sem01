#pragma once

#include "LinkedList.h"
#include <iostream>

using namespace std;

typedef int ElementType;

struct Node
{
	ElementType data;
	Node *next;
	int occurrences;
	
	Node();
	
	explicit Node(const ElementType &value);
};


//------------------------------------------LINKED-LIST--------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
class LinkedList
{
private:
	Node *head;
	int length;

public:
	// Default constructor
	LinkedList();
	
	// Constructor can make a list from array of ElementType
	LinkedList(const ElementType *arrayOfElements, const int &size);
	
	// Default destructor
	~LinkedList();
	
	// Func. to iterate through the list and get the real length of the list
	int countNodes();
	
	// Getter-function
	int getLength();
	
	// Shifts linked list, insert new element at the position of head
	void shift(const ElementType &value); // changes length
	
	// Inserts element, doesn't break the order of the items in the list
	void smartInsert(const ElementType &data); // changes length
	
	// Deletes element with value = <data>
	void smartDelete(const ElementType &data); // changes length
	
	// I was not asked to do this function,
	// so it is not a part of the task :)
	// Func. reverses whole list
	void reverse();
	
	// Prints the whole list
	void printList();
	
	// Print every node with occurrences
	void smartPrint();
	
	// Destroys list recursively
	void destroyList();
	
	// Handles dialog interface
	void linkedListInterface();
};
