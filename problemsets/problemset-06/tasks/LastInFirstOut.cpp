#include "LastInFirstOut.h"

#include <iostream>
#include <exception>

using namespace std;


stackElement::stackElement(const int &value, stackElement *pointerToNext)
{
	data = value;
	next = pointerToNext;
}


myStack::myStack()
{
	topElement = nullptr;
}


myStack::myStack(const int value)
{
	topElement = new stackElement(value, nullptr);
}


myStack::~myStack()
{
	stackElement *current = topElement;
	while (current != nullptr)
	{
		current = topElement->next;
		delete topElement;
		topElement = current;
	}
}


void myStack::capacity(const int &value)
{
	maxCapacity = value;
}


int myStack::capacity()
{
	return maxCapacity;
}


void myStack::push(const int item)
{
	if (this->isFull())
	{
		throw "\nERROR: Can't push() to stack.\n The stack is full.\n";
	}
	
	auto *newElement = new stackElement(item, topElement);
	topElement = newElement;
}


int myStack::pop()
{
	int data = topElement->data;
	
	if (this->isEmpty())
	{
		throw "\nERROR: Can't pop() from stack.\n The stack is empty\n";
	}
	
	auto *pointerToTop = topElement;
	topElement = topElement->next;
	delete pointerToTop;
	return data;
}


int myStack::top()
{
	return topElement->data;
}


bool myStack::isEmpty()
{
	return (topElement == nullptr);
}


int myStack::getSize()
{
	if (this->isEmpty())
	{
		return 0;
	}
	
	int counter = 0;
	stackElement *current = topElement;
	
	while (current != nullptr)
	{
		current = current->next;
		++counter;
	}
	return counter;
}


bool myStack::isFull()
{
	return (this->getSize() == maxCapacity);
}


// Stack.ascii
//           _____________
//        __|_____________|
//     __|_____________|
//  __|_____________|
// |_____________|__
//____|_____________|____
//|______________________|