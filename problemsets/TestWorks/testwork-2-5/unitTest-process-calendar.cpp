#include "testwork-process-calendar.h"

#include <gtest/gtest.h> // Google Test Framework
#include <iostream>

using namespace std;

TEST(testwork_2, calendarParserTest)
{
	auto *list = new LinkedList();
	
	processData("calendar.txt", list);
	
	cout << "Max date: " << list->getHeadValue() << endl;
	
	cout << "\nList of dates:" << endl;
	list->printList();
	
	SUCCEED();
}