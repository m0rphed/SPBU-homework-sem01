#pragma once

#include "Queue.h"
#include <string>
#include <fstream>

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
	
	for (int i = 0; i < n; ++i)
	{
		if (requests[i] != -1)
		{
			cout << endl;
		}
	}
}