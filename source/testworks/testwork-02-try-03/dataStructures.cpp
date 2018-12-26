#include <iostream>
#include "dataStructures.h"


Node::Node(const ElementType &value, Node *pointerToPrevious = nullptr, Node *pointerToNext = nullptr)
{
	data = value;
	previous = pointerToPrevious;
	next = pointerToNext;
}


Node::Node() : data(0), previous(nullptr), next(nullptr)
{
}


DoublyLinkedList::DoublyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}


void DoublyLinkedList::destroyList()
{
	while (head != nullptr)
	{
		Node *pointerToNext = head;
		head = head->next;
		delete pointerToNext;
	}
	tail = nullptr;
}


DoublyLinkedList::~DoublyLinkedList()
{
	destroyList();
}


Node *DoublyLinkedList::getHead()
{
	return this->head;
}


Node *DoublyLinkedList::getTail()
{
	return this->tail;
}


int DoublyLinkedList::getLength()
{
	return this->length;
}


Node *DoublyLinkedList::getNodeAt(const int &position)
{
	if (position < 0)
	{
		return head;
	}
	
	if (position >= 0 && position < length)
	{
		if (position > length / 2)
		{
			auto *current = tail;
			for (int i = length - 1; i > position; --i)
			{
				current = current->previous;
			}
			return current;
		}
		
		auto *currentNode = head;
		for (int i = 0; i < position; ++i)
		{
			currentNode = currentNode->next;
		}
		return currentNode;
	}
	
	if (position >= length)
	{
		return nullptr;
	}
}


void DoublyLinkedList::addTo(const int &position, const ElementType &value)
{
	if (length == 0)
	{
		head = tail = new Node(value);
	}
	else
	{
		auto *next = this->getNodeAt(position);
		
		if (!next)
		{
			tail->next = new Node(value, tail);
			tail = tail->next;
		}
		else if (next == head)
		{
			head = new Node(value, next->previous, next);
			head->next->previous = head;
		}
		else
		{
			next->previous = new Node(value, next->previous, next);
			if (next->previous->previous != nullptr)
			{
				next->previous->previous->next = next->previous;
			}
		}
	}
	++length;
}


void DoublyLinkedList::addToEnd(const ElementType &value)
{
	addTo(length, value);
}


void DoublyLinkedList::removeFrom(const int &position)
{
	if (length == 0)
	{
		return;
	}
	if (position <= 0)
	{
		auto *temp = head;
		head = temp->next;
		
		if (head == nullptr)
		{
			tail = nullptr;
		}
		else
		{
			head->previous = nullptr;
		}
		delete temp;
	}
	else if (position >= length - 1)
	{
		auto *temp = tail;
		tail = temp->previous;
		if (tail == nullptr)
		{
			head = nullptr;
		}
		else
		{
			tail->next = nullptr;
		}
		delete temp;
	}
	else
	{
		Node *temp = getNodeAt(position);
		temp->next->previous = temp->previous;
		temp->previous->next = temp->next;
		delete temp;
	}
	--length;
}


void DoublyLinkedList::print()
{
	using namespace std;
	
	if (length == 0)
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		cout << "[" << length << "]: {";
		auto *temp = head;
		
		while (temp)
		{
			cout << temp->data;
			if (temp->next)
			{
				cout << ", ";
			}
			temp = temp->next;
		}
		cout << "}" << endl;
	}
}


void DoublyLinkedList::printReverse()
{
	using namespace std;
	
	if (length == 0)
	{
		cout << "List is empty!" << endl;
	}
	else
	{
		cout << "[" << length << "]: {";
		auto *temp = tail;
		
		while (temp)
		{
			cout << temp->data;
			if (temp->previous)
			{
				cout << ", ";
			}
			temp = temp->previous;
		}
		cout << "}" << endl;
	}
}
