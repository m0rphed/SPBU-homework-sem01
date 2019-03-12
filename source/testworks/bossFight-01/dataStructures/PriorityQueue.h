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
	
	int getLength();
	
	int front();
	
	int back();
	
	void enqueue(int value, int key);

	int dequeue();
	
	void print();
	
	node *findHighestNode();
};


//// Constructor
//PriorityQueue::PriorityQueue( void )
//{
//	root = tail = nullptr;
//	length = 0;
//}
//
//
//bool PriorityQueue::isEmpty()
//{
//	return (root == nullptr);
//}
//
//
//int PriorityQueue::size()
//{
//	return this->length;
//}
//
//
//int PriorityQueue::front()
//{
//	if (root != nullptr)
//	{
//		return root->data;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//
//int PriorityQueue::back()
//{
//	for (tail = root; tail->next != nullptr; tail = tail->next);
//	return tail->data;
//}
//
//
//void PriorityQueue::enqueue(int value, int key)
//{
//	node *newNode = new node();
//	newNode->data = value;
//	newNode->next = nullptr;
//	if (root == nullptr)
//	{
//		root = newNode;
//		tail = newNode;
//		return;
//	}
//	struct QueueNode *it;
//	struct QueueNode *it1;
//	it = root;
//	it1 = nullptr;
//	while (it != nullptr)
//	{
//		if (it->key < key)
//		{
//			if (it1 != nullptr)
//				it1->next = newNode;
//			newNode->next = it;
//			if (it1 == nullptr)
//				root = newNode;
//			return;
//		}
//		it1 = it;
//		it = it->next;
//	}
//	it1->next = newNode;
//	tail = newNode;
//}
//
//
//int PriorityQueue::dequeue()
//{
//	if (root == nullptr)
//	{
//		cout << "Queue is EMPTY!" << endl;
//		return -1;
//	}
//
//	cout << "Deleted value was: " << root->data << " with key: " << root->key << endl;
//
//	struct QueueNode *temp = root;
//
//	root = root->next;
//
//	if (root == nullptr)
//	{
//		tail = nullptr;
//	}
//
//	auto value = temp->data;
//	delete temp;
//	return value;
//}
//
//
//void PriorityQueue::print()
//{
//	auto *copyOfHead = root;
//
//	cout << "Priority Queue: ";
//
//	while (copyOfHead != nullptr)
//	{
//		cout << copyOfHead->data << " ";
//		copyOfHead = copyOfHead->next;
//	}
//
//	cout << endl;
//}