#include "task-52-circular-linked-list.h"

#include <iostream>
#include <cstdlib>

using namespace std;


CircularList::CircularList()
{
	this->length = 0;
	this->head = nullptr;
}


CircularList::~CircularList()
{
	cout << "list deleted";
}


void CircularList::addElement(int data)
{
	Node *node = new Node();
	node->data = data;
	node->next = this->head;
	this->head = node;
	this->length++;
}


void CircularList::print()
{
	Node *head = this->head;
	int i = 1;
	while (head)
	{
		std::cout << i << ": " << head->data << std::endl;
		head = head->next;
		i++;
	}
}
