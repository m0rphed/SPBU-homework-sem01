#include "DoublyLinkedList.h"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
typedef string TypeOfValue;


myNode::myNode(const TypeOfValue &newName, const TypeOfValue &newPhone)
{
	name = newName;
	phone = newPhone;
	previous = nullptr;
	next = nullptr;
}


myNode::myNode(const TypeOfValue &newName, const TypeOfValue &newPhone, myNode *pointerToPrevious,
               myNode *pointerToNext)
{
	name = newName;
	phone = newPhone;
	
	previous = pointerToPrevious;
	next = pointerToNext;
}


myNode::myNode() : previous(nullptr), next(nullptr)
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
		myNode *pointerToNext = head;
		head = head->next;
		delete pointerToNext;
	}
	
	tail = nullptr;
}


DoublyLinkedList::~DoublyLinkedList()
{
	destroyList();
}


myNode *DoublyLinkedList::getHead()
{
	return this->head;
}


myNode *DoublyLinkedList::getTail()
{
	return this->tail;
}


int DoublyLinkedList::getLength()
{
	return this->length;
}


myNode *DoublyLinkedList::getNodeAt(const int &position)
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
			for (int i = length; i > position; --i)
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


void DoublyLinkedList::addTo(const int &position, const TypeOfValue &username, const TypeOfValue &phone)
{
	if (length == 0)
	{
		head = tail = new myNode(username, phone);
	}
	else
	{
		auto *next = this->getNodeAt(position);
		
		if (!next)
		{
			tail->next = new myNode(username, phone, tail, nullptr);
			tail = tail->next;
		}
		else if (next == head)
		{
			head = new myNode(username, phone, next->previous, next);
			head->next->previous = head;
		}
		else
		{
			next->previous = new myNode(username, phone, next->previous, next);
			if (next->previous->previous != nullptr)
			{
				next->previous->previous->next = next->previous;
			}
		}
	}
	++length;
}


void DoublyLinkedList::addToEnd(const TypeOfValue &username, const TypeOfValue &phone)
{
	addTo(length, username, phone);
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
		myNode *temp = getNodeAt(position);
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
		cout << "[" << length << "]: {" << endl;
		
		auto *temp = head;
		while (temp)
		{
			cout << "| " << temp->name << " | --> | " << temp->phone << " |";
			if (temp->next)
			{
				cout << ", " << endl;
			}
			temp = temp->next;
		}
		cout << "}" << endl;
	}
}


void DoublyLinkedList::setNodeAt(const int &index, myNode *newNode)
{
}


DoublyLinkedList *DoublyLinkedList::sliceList(const int &fromPosition, const int &toPosition)
{
	// Case 0: throw ERROR
	if (fromPosition < 0 || toPosition >= length)
	{
		cerr << "ERROR: position is out of range" << endl;
		throw std::exception();
	}
	
	// Case 1: from beginning to some position
	// Case 2: from position_1 to some position_2
	// Case 3: from some position to end
}