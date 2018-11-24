#include "task-52-circular-linked-list.h"

#include <iostream>
#include <exception>

using namespace std;


CircularList::Node::Node(int value)
{
	data = value;
	next = this;
}


CircularList::LinkedList::LinkedList(int headValue)
{
	listHead = new Node(headValue);
}


CircularList::LinkedList::~LinkedList()
{
	deleteList();
}


bool CircularList::LinkedList::isHead(CircularList::Node *element)
{
	return (listHead == element);
}


void CircularList::LinkedList::shift()
{
	auto *previous = listHead;
	auto *current = listHead->next;
	
	while (!isHead(current))
	{
		previous = current;
		current = current->next;
	}
	
	cout << "\nDelete listHead with key: " << current->data << endl;
	previous->next = current->next;
	listHead = current->next;
	delete current;
}


int CircularList::LinkedList::length()
{
	int counter = 0;
	if (listHead == nullptr)
	{
		cout << "\nCircular list is empty (or do not exist)." << endl;
		return counter;
	}
	
	auto *current = listHead->next;
	
	do
	{
		++counter;
		current = current->next;
		
	} while (!isHead(current));
	
	return counter;
}


void CircularList::LinkedList::insert(const int key)
{
	Node *newElement = new CircularList::Node(key);
	newElement->next = listHead;
	
	// make a copy of listHead and listHead->next
	auto *previous = listHead;
	auto *current = listHead->next;
	
	while (!isHead(current))
	{
		previous = current;
		current = current->next;
	}
	
	previous->next = newElement;
}


void CircularList::LinkedList::kill(int key)
{
	if (listHead->data == key)
	{
		shift();
		return;
	}
	
	// make a copy of listHead and listHead->next
	auto *previous = listHead;
	auto *current = listHead->next;
	
	while (!isHead(current))
	{
		if (current->data == key)
		{
			cout << "\nDelete element with key: " << current->data << endl;
			previous->next = current->next;
			delete current;
			return;
		}
		else
		{
			previous = current;
			current = current->next;
		};
	}
	
	cout << "\nNo element with such key was found." << endl;
}


void CircularList::LinkedList::print()
{
	cout << listHead->data << "-->";
	
	auto *current = listHead->next;
	
	while (!isHead(current))
	{
		cout << current->data << "-->";
		current = current->next;
	}
	
	cout << "head" << endl;
}


void CircularList::LinkedList::deleteList()
{
	auto *current = listHead->next;
	
	while (!isHead(current))
	{
		auto *temp = current;
		current = current->next;
		
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
