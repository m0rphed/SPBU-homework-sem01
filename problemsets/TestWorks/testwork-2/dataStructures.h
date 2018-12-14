#pragma once

typedef int ElementType;

struct Node
{
	ElementType data;
	Node *next;
	
	Node();
	
	explicit Node(const ElementType &value);
};


//------------------------------------------LINKED-LIST--------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------
class MyLinkedList
{
private:
	Node *head;
	int length;

public:
	// Default constructor
	MyLinkedList();
	
	// Constructor can make a list from array of ElementType
	MyLinkedList(const ElementType *arrayOfElements, const int &size);
	
	// Default destructor
	~MyLinkedList();
	
	// Func. to iterate through the list and get the real length of the list
	int countNodes();
	
	// Getter-function
	int getLength();
	
	Node *getHead();
	
	// Shifts linked list, insert new element at the position of head
	void shift(const ElementType &value); // changes length
	
	// Inserts element to the end
	void insert(const ElementType &value);
	
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
	
	// Destroys list recursively
	void destroyList();
	
	// Handles dialog interface
	void linkedListInterface();
};