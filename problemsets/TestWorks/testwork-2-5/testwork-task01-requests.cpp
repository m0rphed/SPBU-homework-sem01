#include "testwork-task01-requests.h"
#include "Queue.h"
#include <iostream>

using namespace std;

// Дано n – количество запросов (n чисел от -1 до 10^9 – запросы).
// Если запрос равен -1, следует убрать элемент из начала очереди (если она не пуста).
// Иначе следует добавить этот элемент в конец очереди.
// Для каждого запроса -1 вывести убираемый элемент, либо -1, если очередь пуста.


void handleInput(const int &n, int *requests)
{
	cout << "\nStarted testing module..." << endl;
	cout << "\nGot array of requests:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << requests[i] << ", ";
	}
	
	auto *myQueue = new Queue;
	for (int i = 0; i < n; ++i)
	{
		if (requests[i] != -1)
		{
			cout << "Enqueued with value: " << requests[i] << endl;
			myQueue->enqueue(requests[i]);
		}
		else
		{
			cout << "Dequeued value: " << myQueue->dequeue() << endl;
		}
	}
	
	cout << "At the end of the day we have: " << endl;
	myQueue->printQueue();
	delete myQueue;
}


void handleInput(const int &n, int *requests, Queue &myQueue)
{
	cout << "\nStarted testing module..." << endl;
	cout << "\nGot array of requests:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << requests[i] << ", ";
	}
	
	for (int i = 0; i < n; ++i)
	{
		if (requests[i] != -1)
		{
			cout << "Enqueued with value: " << requests[i] << endl;
			myQueue.enqueue(requests[i]);
		}
		else
		{
			cout << "Dequeued value: " << myQueue.dequeue() << endl;
		}
	}
	
	cout << "At the end of the day we have: " << endl;
	myQueue.printQueue();
}
