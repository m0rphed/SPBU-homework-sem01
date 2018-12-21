#pragma once

#include <iostream>
#include <locale>

using namespace std;
typedef string ElementType;

struct Node
{
	ElementType data = "";
	Node *next;
	
	Node();
	
	explicit Node(ElementType &value);
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
	LinkedList(ElementType *arrayOfElements, const int &size);
	
	// Default destructor
	~LinkedList();
	
	// Func. to iterate through the list and get the real length of the list
	int countNodes();
	
	std::string getHeadValue();
	
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
	
	// Destroys list recursively
	void destroyList();
	
	// Handles dialog interface
	void linkedListInterface();
};