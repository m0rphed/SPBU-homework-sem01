#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef struct QueueNode
{
	int data = 0;
	int key;
	QueueNode *next = nullptr;
} node;


class PriorityQueue
{
	int length = 0;
	node *head;
	node *tail;

public:
	PriorityQueue();
	
	bool isEmpty();
	
	int size();
	
	int front();
	
	int back();
	
	void enqueue(int value, int key);
	
<<<<<<< HEAD
	int dequeue();
	
	void print();
	
	node *findHighestNode();
=======
	void dequeue();
>>>>>>> parent of 917e341... Updated
};


// Constructor
PriorityQueue::PriorityQueue( void )
{
	head = tail = nullptr;
	length = 0;
}


bool PriorityQueue::isEmpty()
{
	return (head == nullptr);
}


int PriorityQueue::size()
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
	node *newNode = new node();
	newNode->data = value;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
		return;
	}
	struct QueueNode *it;
	struct QueueNode *it1;
	it = head;
	it1 = nullptr;
	while (it != nullptr)
	{
		if (it->key < key)
		{
			if (it1 != nullptr)
				it1->next = newNode;
			newNode->next = it;
			if (it1 == nullptr)
				head = newNode;
			return;
		}
		it1 = it;
		it = it->next;
	}
	it1->next = newNode;
	tail = newNode;
}

void PriorityQueue::dequeue()
{
	if (head == nullptr)
	{
		cout << "Queue is EMPTY!" << endl;
		return;
	}
	cout << "Deleted value was: " << head->data << " with key: " << head->key << endl;
	struct QueueNode *temp = head;
	head = head->next;
	if (head == nullptr)
	{
		tail = nullptr;
	}
	
	delete temp;
}


void PriorityQueue::front()
{
	if (head == nullptr)
	{
		cout << "Peeked Value" << endl;
	}
	
}


void PriorityQueue::print()
{
	auto *copyOfHead = head;
	
	cout << "Priority Queue: ";
	
	while (copyOfHead != nullptr)
	{
		cout << copyOfHead->data << " ";
		copyOfHead = copyOfHead->next;
	}
	
	cout << endl;
}