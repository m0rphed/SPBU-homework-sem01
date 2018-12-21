#include "PriorityQueue.h"

// Constructor
PriorityQueue::PriorityQueue()
{
	head = tail = nullptr;
	length = 0;
}


bool PriorityQueue::isEmpty()
{
	return (head == nullptr);
}


int PriorityQueue::getLength()
{
	return this->length;
}


int PriorityQueue::front()
{
	if (head != nullptr)
	{
		return head->data;
	}
	else
	{
		return -1;
	}
}


int PriorityQueue::back()
{
	for (tail = head; tail->next != nullptr; tail = tail->next);
	return tail->data;
}


void PriorityQueue::enqueue(int value, int key)
{
	auto *newNode = new node();
	
	newNode->data = value;
	newNode->next = nullptr;
	
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		return;
	}
	
	auto *previous = head;
	node *current;
	
	while (previous != nullptr)
	{
		if (previous->key < key)
		{
			if (current)
			{
				current->next = newNode;
			}
			
			newNode->next = previous;
			
			if (!current)
			{
				head = newNode;
			}
			
			return;
		}
		
		current = previous;
		previous = previous->next;
	}
	
	current->next = newNode;
	tail = newNode;
	++length;
}


int PriorityQueue::dequeue()
{
	if (!head)
	{
		cout << "Queue is empty." << endl;
		return -1;
	}
	
	node *maxNode = this->findHighestNode();
	
	for (auto *headCopy = head; headCopy->next != nullptr; headCopy = headCopy->next)
	{
		if ((headCopy->next)->key == maxNode->key)
		{
			(headCopy->next)->next = ((headCopy->next)->next)->next;
			break;
		}
	}
	
	--length;
	cout << "Deleted value was: " << maxNode->data << " with key: " << maxNode->key << endl;
	delete maxNode;
}


void PriorityQueue::print()
{
	auto *copyOfHead = head;
	
	cout << "Priority Queue: " << endl;
	
	while (copyOfHead)
	{
		cout << copyOfHead->data << " ";
		copyOfHead = copyOfHead->next;
	}
	cout << endl;
}


node *PriorityQueue::findHighestNode()
{
	node *highest = head;
	int maxKey = head->key;
	
	for (node *headCopy = head; headCopy->next != nullptr; headCopy = headCopy->next)
	{
		if (headCopy->key > maxKey)
		{
			highest = headCopy;
			maxKey = headCopy->key;
		}
	}
	return highest;
}

