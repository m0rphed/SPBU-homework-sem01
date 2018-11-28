#include "LastInFirstOut.h"

#include <iostream>
#include <exception>

using namespace std;


stackElement::stackElement(const int &value, stackElement *pointerToNext)
{
	data = value;
	next = pointerToNext;
}


int stackElement::getData()
{
	return this->data;
}


void stackElement::setData(const int value)
{
	this->data = value;
}


stackElement *stackElement::getNext()
{
	return this->next;
}


void stackElement::setNext(stackElement *nextElement)
{
	this->next = nextElement;
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
		current = topElement->getNext();
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
	int data = topElement->getData();
	
	if (this->isEmpty())
	{
		throw "\nERROR: Can't pop() from stack.\n The stack is empty\n";
	}
	
	auto *pointerToTop = topElement;
	topElement = topElement->getNext();
	delete pointerToTop;
	return data;
}


int myStack::top()
{
	return topElement->getData();
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
		current = current->getNext();
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