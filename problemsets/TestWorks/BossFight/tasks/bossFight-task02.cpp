#include "bossFight-task02.h"
#include "../dataStructures/PriorityQueue.h"

// Реализовать очередь с приоритетами в виде
// отдельного модуля.
// Модуль должен иметь функцию enqueue(),
// принимающую на вход значение и численный приоритет, и функцию dequeue(),
// возвращающую значение с наивысшим приоритетом и удаляющую его из очереди.
// Если очередь пуста, dequeue() должен возвращать -1.

int main()
{
	auto *myQueue = new PriorityQueue;
	
	int command = 0;
	int value = 0;
	int key = 0;
	
	do
	{
		cout << "Choose operation: " << endl;
		cout << "\t0) Exit" << endl;
		cout << "\t1) Enqueue" << endl;
		cout << "\t2) Dequeue" << endl;
		cout << "\t3) Print" << endl;
		
		cin >> command;
		if (command == 1)
		{
			cin >> value >> key;
			myQueue->enqueue(value, key);
		}
		else if (command == 2)
		{
			myQueue->dequeue();
		}
		else if (command == 3)
		{
			myQueue->print();
		}
		else
		{
			cout << "Wrong command" << endl;
			break;
		}
	} while (command != 0);
	
	return 0;
}