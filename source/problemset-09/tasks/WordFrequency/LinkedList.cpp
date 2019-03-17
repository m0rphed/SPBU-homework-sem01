#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

HashTableComponents::ListNode::ListNode(const std::string &newKey, HashTableComponents::ListNode *nextNode)
{
	this->key = newKey;
	this->next = nextNode;
}

HashTableComponents::List::~List()
{
	auto *headCopy = head;
	while (headCopy)
	{
		auto *temp = headCopy;
		headCopy = headCopy->next;
		delete temp;
	}
}

void HashTableComponents::List::addToList(const std::string &key)
{
	auto *newList = new ListNode(key);

	if (!head)
	{
		head = newList;
	}

	auto *current = head;

	while (current->next)
	{
		current = current->next;
	}

	current->next = newList;
}

bool HashTableComponents::List::isEmpty()
{
	return head == nullptr;
}

int HashTableComponents::List::countElements()
{
	int counter = 0;
	auto *current = head;

	while (current)
	{
		current = current->next;
		++counter;
	}

	return counter;
}

void HashTableComponents::List::printList()
{
	auto *temp = head;

	while (temp)
	{
		cout << temp->key << ", ";
		temp = temp->next;
	}

	cout << endl;
}

void HashTableComponents::List::increaseCapacity()
{
	++capacity;
}
