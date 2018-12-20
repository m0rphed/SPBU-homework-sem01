#include "DoublyLinkedList.h"

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;
typedef string TypeOfValue;


Node::Node(const TypeOfValue &newName, const TypeOfValue &newPhone)
{
	name = newName;
	phone = newPhone;
	previous = nullptr;
	next = nullptr;
}


Node::Node(const TypeOfValue &newName, const TypeOfValue &newPhone, Node *previousNode,
           Node *nextNode)
{
	name = newName;
	phone = newPhone;
	previous = previousNode;
	next = nextNode;
}


Node::Node() : previous(nullptr), next(nullptr)
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


void DoublyLinkedList::insertTo(const int &position, const TypeOfValue &username, const TypeOfValue &phone)
{
	if (length == 0)
	{
		head = tail = new Node(username, phone);
	}
	else
	{
		auto *next = this->getNodeAt(position);
		
		if (!next)
		{
			tail->next = new Node(username, phone, tail, nullptr);
			tail = tail->next;
		}
		else if (next == head)
		{
			head = new Node(username, phone, next->previous, next);
			head->next->previous = head;
		}
		else
		{
			next->previous = new Node(username, phone, next->previous, next);
			if (next->previous->previous)
			{
				next->previous->previous->next = next->previous;
			}
		}
	}
	++length;
}


void DoublyLinkedList::append(const TypeOfValue &username, const TypeOfValue &phone)
{
	insertTo(length, username, phone);
}


void DoublyLinkedList::remove(const int &position)
{
	if (length == 0)
	{
		return;
	}
	if (position <= 0)
	{
		auto *temp = head;
		head = temp->next;
		
		if (!head)
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
		if (!tail)
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


void DoublyLinkedList::checkPosition(const int &position)
{
	if (position >= this->length || position < 0)
	{
		cerr << "ERROR: position is out of range" << endl;
		throw runtime_error(string("OUT OF RANGE!"));
	}
}


void DoublyLinkedList::resetNode(const int &position, Node *newNode)
{
	checkPosition(position);
	auto *node = this->getNodeAt(position);
	
	newNode->previous = node->previous;
	newNode->next = node->next;
	
	if(newNode->previous)
	{
		(newNode->previous)->next = newNode;
	}

	if(newNode->next)
	{
		(newNode->next)->previous = newNode;
	}
	
	delete node;
}


DoublyLinkedList *DoublyLinkedList::getSubList(const int &beginning, const int &theEnd)
{
	auto subList = new DoublyLinkedList();
	
	if (beginning < 0 || theEnd > this->length)
	{
		cerr << "ERROR: position is out of range" << endl;
		throw runtime_error("FUUUUUCK!");
	}
	
	int index = beginning;
	while (index < theEnd)
	{
		auto *current = this->getNodeAt(index);
		subList->append(current->name, current->phone);
		++index;
	}
	
	return subList;
}


void DoublyLinkedList::resetNodeData(const int &position, const TypeOfValue &username, const TypeOfValue &phone)
{
	checkPosition(position);
	auto *node = this->getNodeAt(position);
	node->name = username;
	node->phone = phone;
}
