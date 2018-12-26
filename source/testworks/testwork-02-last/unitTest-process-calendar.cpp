#include "testwork-task01-requests.h"
#include "Queue.h"

#include <gtest/gtest.h> // Google Test Framework
#include <iostream>

using namespace std;

TEST(testwork_2, requestTest)
{
	auto *myQueue = new Queue();
	
	const int n = 10;
	int arrayOfCommands[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	handleInput(n, arrayOfCommands, myQueue);
	
	delete myQueue;
	SUCCEED();
}


TEST(testwork_2, requestTest2)
{
	auto *myQueue = new Queue();
	
	const int n = 11;
	int arrayOfCommands[n] = {1, -1, -1, 3, 4, 5, 6, -1, 8, -1, 10};
	
	handleInput(n, arrayOfCommands, myQueue);
	
	delete myQueue;
	SUCCEED();
}

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
