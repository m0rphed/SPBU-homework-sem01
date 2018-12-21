#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class PriorityQueue
{
	typedef struct QueueNode
	{
		int value;
		struct QueueNode *next;
	} node;
	
	int numberOfNodes;
	node *head;
	node *tail;

public:
	PriorityQueue();
	
	bool empty();
	
	int size();
	
	int front();
	
	int back();
	
	void enqueue();
	
	void dequeue();
};


bool PriorityQueue::empty()
{
	return (head == NULL);
}


int PriorityQueue::size()
{
	return numberOfNodes;
}


int PriorityQueue::front()
{
	if (head != NULL)
		return head->value;
	else
		return -1;
}


int PriorityQueue::back()
{
	for (tail = head; tail->next != NULL; tail = tail->next);
	return tail->value;
}


void PriorityQueue::enqueue(int newValue)
{
	node *temp;
	node *current;
	
	temp = (node *) calloc(1, sizeof(node));
	temp->value = newValue;
	
	// Inserting in the beginning of the queue
	if (head == NULL || newValue < head->value)
	{
		temp->next = head;
		head = temp;
	}
		// Inserting middle/end of queue
	else
	{
		current = head;
		
		// Navigate through the list until the next node value is LARGER than the current value, but stop once we hit the end of the list
		while (current->next != NULL && current->next->value < newValue)
		{
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
	}
	
	numberOfNodes++;
}


void PriorityQueue::dequeue()
{
	node *temp;
	
	if (head != nullptr)
	{
		temp = head;
		head = head->next;
		
		free(temp);
		temp = nullptr;
		
		numberOfNodes--;
	}
}


// Constructor
PriorityQueue::PriorityQueue()
{
	head = tail = nullptr;
	numberOfNodes = 0;
}


int main(int argc, char **argv)
{
	PriorityQueue myQueue = PriorityQueue();
	
	cout << "The queue should be empty: " << myQueue.empty() << endl;
	cout << "The size of the queue should be 0: " << myQueue.size() << endl;
	myQueue.enqueue(3);
	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
	myQueue.enqueue(1);
	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
	myQueue.enqueue(2);
	myQueue.dequeue();
	cout << "The size of the queue should be 2: " << myQueue.size() << endl;
	
	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
	myQueue.enqueue(4);
	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
	myQueue.enqueue(5);
	cout << "myQueue.front() = " << myQueue.front() << " myQueue.back() = " << myQueue.back() << endl;
	myQueue.dequeue();
	
	cout << "The queue should NOT be empty: " << myQueue.empty() << endl;
	cout << "The size of the queue should be 3: " << myQueue.size() << endl;
	
	// Print out the queue
	while (!myQueue.empty())
	{
		cout << myQueue.front() << " " << endl;
		myQueue.dequeue();
	}
	
	return 0;
}
