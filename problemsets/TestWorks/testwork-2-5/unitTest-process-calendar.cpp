#include "testwork-process-calendar.h"

#include <gtest/gtest.h> // Google Test Framework
#include <iostream>

using namespace std;

TEST(testwork_2, calendarParserTest)
{
	auto *list = new LinkedList();
	processData("calendar.txt", list);
	list->printList();
	FAIL();
}