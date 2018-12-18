#include "CircularLinkedList.h"

#include <iostream>
#include <exception>

using namespace std;
using namespace CircularList;


// Constructor for initializing node of a circular list
Node::Node(int value)
{
	data = value;
	next = this;
}

int Node::getData()
{
	return this->data;
}


Node *Node::getNext()
{
	return this->next;
}


void Node::setData(const int value)
{
	this->data = value;
}


void Node::setNext(Node *pointerToNext)
{
	this->next = pointerToNext;
}


// Init constructor of the class
LinkedList::LinkedList(int headValue)
{
	listHead = new Node(headValue);
}


// Init destructor of the class
LinkedList::~LinkedList()
{
	deleteList();
}


// Returns TRUE if given 'element' = HEAD
bool LinkedList::isHead(const Node *element)
{
	return (listHead == element);
}


// Shifting head
void LinkedList::shift()
{
	if (this->length() == 1)
	{
		cout << "\nCould not shift list with only one element!" << endl;
		return;
	}
	
	auto *previous = listHead;
	auto *current = listHead->getNext();
	
	while (!this->isHead(current))
	{
		previous = current;
		current = current->getNext();
	}
	
	cout << "\nDelete head of the list with key: " << current->getData() << endl;
	
	previous->setNext(current->getNext());
	listHead = current->getNext();
	
	// destroy current element
	delete current;
}


int LinkedList::length()
{
	// Case: an empty list.
	if (listHead == nullptr)
	{
		cout << "\nCircular list is empty (or do not exist)." << endl;
		return 0;
	}
	
	int counter = 0;
	auto *current = listHead;
	
	do
	{
		++counter;
		current = current->getNext();
		
	} while (!this->isHead(current));
	
	return counter;
}


void LinkedList::insert(const int key)
{
	Node *newElement = new Node(key);
	
	// Case 1: list is empty.
	// We need to insert HEAD
	if (this->length() == 0)
	{
		cout << "\t => New head element: " << key << endl;
		listHead = newElement;
		return;
	}
	
	// Case 2: circular list is not empty
	newElement->setNext(listHead);
	
	// make a copy of listHead and listHead->next
	auto *previous = listHead;
	auto *current = listHead->getNext();
	
	while (!this->isHead(current))
	{
		previous = current;
		current = current->getNext();
	}
	
	previous->setNext(newElement);
}


// Deletes element by given key
void LinkedList::kill(int key)
{
	// Case 1: killing HEAD of the list <- must be done very carefully!
	
	// Case 1a: list has only one element <=> HEAD,
	// so we need to destroy the list.
	if (listHead->getData() == key && this->length() == 1)
	{
		delete listHead;
		cout << "\nHead element of the list was deleted!" << endl;
		
		listHead = nullptr;
		return;
	}
		// Case 1b: list have more than one element <-- we need to shift HEAD
	else if (listHead->getData() == key)
	{
		shift();
		return;
	}
	
	// Case 2: killing any other element by the 'key'
	
	// make a copy of listHead and listHead->next
	auto *previous = listHead;
	auto *current = listHead->getNext();
	
	while (!this->isHead(current))
	{
		if (current->getData() == key)
		{
			cout << "\nDelete element with key: " << current->getData() << endl;
			previous->setNext(current->getNext());
			delete current;
			return;
		}
		else
		{
			previous = current;
			current = current->getNext();
		};
	}
	
	cout << "\nNo element with such key was found." << endl;
}


void LinkedList::print()
{
	cout << listHead->getData() << "-->";
	
	auto *current = listHead->getNext();
	
	while (!this->isHead(current))
	{
		cout << current->getData() << "-->";
		current = current->getNext();
	}
	
	cout << "head" << endl;
}


void LinkedList::deleteList()
{
	// Empty list case
	if (!listHead)
	{
		return;
	}
	
	auto *current = listHead->getNext();
	
	while (!this->isHead(current))
	{
		auto *temp = current;
		current = current->getNext();
		
		try
		{
			delete temp;
		} catch (exception &message)
		{
			cerr << message.what() << endl;
			throw "ERROR: Trying to delete an element that does not exist.\n";
		}
	}
	
	delete listHead;
}


Node *LinkedList::getHead()
{
	return listHead;
}


void LinkedList::setHead(Node *newHead)
{
	listHead = newHead;
}
