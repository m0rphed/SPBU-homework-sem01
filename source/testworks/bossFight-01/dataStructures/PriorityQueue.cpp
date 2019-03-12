#include "PriorityQueue.h"


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

	auto value =  maxNode->data;
	return value;
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


//
//bool PriorityQueue::empty()
//{
//	return (root == nullptr);
//}
//
//
//int PriorityQueue::size()
//{
//	return numberOfNodes;
//}
//
//
//int PriorityQueue::front()
//{
//	if (root)
//	{
//		return root->value;
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
//	return tail->value;
//}
//
//
//void PriorityQueue::enqueue(const int &newValue)
//{
//	node *temp;
//	node *current;
//
//	temp = new node;
//	temp->value = newValue;
//
//	// Inserting in the beginning of the queue
//	if (root == nullptr || newValue < root->value)
//	{
//		temp->next = root;
//		root = temp;
//	}
//		// Inserting middle/end of queue
//	else
//	{
//		current = root;
//
//		// Go through the list until the next node value
//		// is LARGER than the current value,
//		// but stop once we hit the end of the list
//		while (current->next != nullptr && current->next->value < newValue)
//		{
//			current = current->next;
//		}
//		temp->next = current->next;
//		current->next = temp;
//	}
//
//	++numberOfNodes;
//}
//
//
//void PriorityQueue::dequeue()
//{
//	node *temp = nullptr;
//
//	if (root)
//	{
//		temp = root;
//		root = root->next;
//
//		delete temp;
//		--numberOfNodes;
//	}
//}
//
//
//// Constructor
//PriorityQueue::PriorityQueue()
//{
//	root = tail = nullptr;
//	numberOfNodes = 0;
//}
//
//
//void queueTest()
//{
//	PriorityQueue myQueue = PriorityQueue();
//
//	cout << "The queue should be empty: " << myQueue.empty() << endl;
//	cout << "The size of the queue should be 0: " << myQueue.size() << endl;
//	myQueue.enqueue(3);
//	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
//	myQueue.enqueue(1);
//	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
//	myQueue.enqueue(2);
//	myQueue.dequeue();
//	cout << "The size of the queue should be 2: " << myQueue.size() << endl;
//
//	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
//	myQueue.enqueue(4);
//	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
//	myQueue.enqueue(5);
//	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
//	myQueue.dequeue();
//
//	cout << "The queue should NOT be empty: " << myQueue.empty() << endl;
//	cout << "The size of the queue should be 3: " << myQueue.size() << endl;
//
//	// Print out the queue
//	while (!myQueue.empty())
//	{
//		cout << myQueue.front() << " " << endl;
//		myQueue.dequeue();
//	}
//}
