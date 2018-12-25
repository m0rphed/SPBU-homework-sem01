#include "Queue.h"

void Queue::enqueue(const ElementType &value)
{
	if (isEmpty())
	{
		first = new Node(value);
		last = first;
	}
	else
	{
		last->next = new Node(value);
		last = last->next;
	}
}


ElementType Queue::dequeue()
{
	if (!isEmpty())
	{
		ElementType currentData = first->data;
		Node *currentElement = first;
		first = first->next;
		
		delete currentElement;
		return currentData;
	}
	
	// if queue is empty then return -1
	return -1;
}


void Queue::deleteQueue()
{
	while (!isEmpty())
	{
		dequeue();
	}
}


void Queue::printQueue()
{
	auto *current = first;
	if (isEmpty())
	{
		cout << "\nThe queue is empty." << endl;
	}
	
	cout << "Queue: ";
	for (auto *current = first; current != nullptr; current = current->next)
	{
		cout << current->data << " <-- ";
	}
	cout << "." << endl;
}


int Queue::queueSize()
{
	return size;
}


void queueInterface()
{
	int option = 0;
	int value = 0;
	
	auto *myQueue = new Queue();
	
	do
	{
		cout << "=> Enter your choice:" << endl;
		cout << "\t 0) EXIT" << endl;
		cout << "\t 1) Insert an element in queue" << endl;
		cout << "\t 2) Delete an element from queue" << endl;
		cout << "\t 3) Display queue" << endl;
		cout << "\t 4) Queue Size" << endl;
		
		cin >> option;
		switch (option)
		{
			case 1:
				cout << "Enter value: ";
				cin >> value;
				myQueue->enqueue(value);
				break;
			
			case 2:
				if (!myQueue->isEmpty())
				{
					cout << "Dequeued element is: " << myQueue->dequeue() << endl;
				}
				else
				{
					cout << "Queue is empty! Nothing to dequeue." << endl;
				}
				break;
			
			case 3:
				myQueue->printQueue();
				break;
			
			case 4:
				cout << "Size of the queue: " << myQueue->queueSize() << endl;
				break;
			
			case 0:
				cout << "-- EXIT --" << endl;
				break;
			
			default:
				cout << "Wrong command! Enter again:" << endl;
				break;
		}
	} while (option != 0);
}
