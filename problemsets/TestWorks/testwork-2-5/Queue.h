#pragma once

#include <iostream>

using namespace std;
typedef int ElementType;

class Queue
{
	struct Node
	{
	public:
		ElementType data;
		Node *next = nullptr;
		
		explicit Node(ElementType value = 0) : data(value)
		{
		}
	};

private:
	int size = 0;
	Node *first = nullptr;
	Node *last = nullptr;

public:
	Queue() : first(nullptr), last(nullptr), size(0)
	{
	}
	
	~Queue()
	{
		deleteQueue();
	};
	
	inline bool isEmpty() const
	{
		return (first == nullptr);
	}
	
	void enqueue(const ElementType &value);
	
	ElementType dequeue();
	
	void printQueue();
	
	int queueSize();
	
	void deleteQueue();
};
