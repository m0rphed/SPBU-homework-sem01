#include <iostream>

using namespace std;

typedef struct QueueNode
{
	int data = 0;
	int key;
	QueueNode *next = nullptr;
} node;


class PriorityQueue
{
	node *head;
	node *tail;
	int length = 0;

public:
	PriorityQueue();
	
	bool isEmpty();
	
	int getLength();
	
	int front();
	
	int back();
	
	void enqueue(int value, int key);
	
	int dequeue();
	
	void print();
	
	node *findHighestNode();
};
