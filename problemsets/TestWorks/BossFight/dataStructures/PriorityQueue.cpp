#include "PriorityQueue.h"

// Constructor
PriorityQueue::PriorityQueue(void)
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
	
	auto *temp = head;
	head = head->next;
	
	if (!head)
	{
		tail = nullptr;
	}
	
	delete temp;
	--length;
	cout << "Deleted value was: " << head->data << " with key: " << head->key << endl;
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