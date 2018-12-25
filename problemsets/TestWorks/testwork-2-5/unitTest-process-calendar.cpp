#include "testwork-task01-requests.h"
#include "Queue.h"

#include <gtest/gtest.h> // Google Test Framework
#include <iostream>

using namespace std;

TEST(testwork_2, calendarParserTest)
{
	auto *myQueue = new Queue();
	
//	handleInput("calendar.txt", myQueue);
//
//	cout << "Max date: " << myQueue->getHeadValue() << endl;
//
//	cout << "\nList of dates:" << endl;
//	myQueue->printList();
	
	delete myQueue;
	SUCCEED();
}