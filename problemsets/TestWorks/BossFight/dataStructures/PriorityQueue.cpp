#include "PriorityQueue.h"

//
//bool PriorityQueue::empty()
//{
//	return (head == nullptr);
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
//	if (head)
//	{
//		return head->value;
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
//	for (tail = head; tail->next != nullptr; tail = tail->next);
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
//	if (head == nullptr || newValue < head->value)
//	{
//		temp->next = head;
//		head = temp;
//	}
//		// Inserting middle/end of queue
//	else
//	{
//		current = head;
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
//	if (head)
//	{
//		temp = head;
//		head = head->next;
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
//	head = tail = nullptr;
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
