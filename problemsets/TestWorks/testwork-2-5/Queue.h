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
	int size;
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


/*
int main( )
{
  queue<int> q;
  
  q.enqueue( 10 );
  q.enqueue( 45 );
  q.enqueue( 34 );
  q.enqueue( 12 );
  q.enqueue( 89 );
  q.enqueue( 17 );
  
  q.display( );
  
  for ( int i = 0; i < 3; i++ )
    q.dequeue( );
  
  q.display( );
  
  q.makeempty( );
  
  q.display( );

  cin.get( );
  return 0;
}
*/
