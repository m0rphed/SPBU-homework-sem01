#pragma once

#include "Queue.h"

// Задание:
// Дано n – количество запросов (n чисел от -1 до 10^9 – запросы).
// Если запрос равен -1, следует убрать элемент из начала очереди (если она не пуста).
// Иначе следует добавить этот элемент в конец очереди.
// Для каждого запроса -1 вывести убираемый элемент, либо -1, если очередь пуста.

void handleInput(const int &n, int *requests);

void handleInput(const int &n, int *requests, Queue *myQueue);