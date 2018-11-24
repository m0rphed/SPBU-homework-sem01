#include "../testFixtures/LinkedListFixture.h"
#include "../tasks/LinkedList/task-51-linked-list.h"

#include <gtest/gtest.h> // Google Test Framework

#include <cstdlib>
#include <iostream> // cin, cout, endl
#include <locale>   // setlocale(LC_ALL, "Russian")

using namespace std;


// used in qsort() from 'cstdlib'
int compare(const void *a, const void *b)
{
	const int *x = (int *) a;
	const int *y = (int *) b;
	
	if (*x > *y)
	{
		return 1;
	}
	
	else if (*x < *y)
	{
		return -1;
	}
	
	return 0;
}


TEST_F(ListFixture, insertedValuesTest)
{
	const int length = 10;
	auto *testArray = new int[length]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	ListFixture::insertTestValues(testArray, length);
	
	qsort(testArray, length, sizeof(int), compare);
	
	// ::testing::AssertionSuccess() <=> true
	ASSERT_TRUE(ListFixture::checkList(testArray, length));
	
	cout << endl;
	LinkedList::printList(listHead);
	
	delete[] testArray;
}


TEST_F(ListFixture, simpleDialogLoopTest)
{
	// Enable Russian in console
	setlocale(LC_ALL, "Russian");
	
	const int length = 10;
	auto *testArray = new int[length]{1, 1, 1, 2, 1, 3, 1, 4, 3, 0};
	
	cout << "\n\t\t<=== Начать тестирование последовательности комманд ===>" << endl;
	simulateDialogLoop(testArray, length);
	
	cout << "Длина списка: " << LinkedList::length(listHead) << endl;
	GTEST_ASSERT_EQ(LinkedList::length(listHead), 4);
	
	delete[] testArray;
}


TEST_F(ListFixture, complicatedDialogLoopTest)
{
	// Enable Russian in console
	setlocale(LC_ALL, "Russian");
	
	const int length = 26;
	auto *testArray = new int[length]{1, 1, 1, 3, 1, 3, 1, 7, 2, 3, 2, 3, 2,
	                                  3, 3, 666, 1, 42, 3, 2, 1, 2, 42, 3, 0};
	
	cout << "\n\t\t<=== Начать тестирование последовательности комманд ===>" << endl;
	simulateDialogLoop(testArray, length);
	
	cout << "Длина списка: " << LinkedList::length(listHead) << endl;
	GTEST_ASSERT_EQ(LinkedList::length(listHead), 1);
	GTEST_ASSERT_EQ(listHead->data, 7);
	
	delete[] testArray;
}


TEST_F(ListFixture, insertThenDeleteOddElements)
{
	const int length = 10;
	
	auto *testArray = new int[length]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	auto *testCommands = new int[length]{2, 9, 2, 7, 2, 5, 2, 3, 2, 1};
	auto *onlyOddElements = new int[5]{2, 4, 6, 8, 10};
	
	ListFixture::insertTestValues(testArray, length);
	
	cout << "\n\t\t<=== Начать тестирование последовательности комманд ===>" << endl;
	simulateDialogLoop(testCommands, length);
	
	// ::testing::AssertionSuccess() <=> true
	ASSERT_TRUE(ListFixture::checkList(onlyOddElements, 5));
	
	cout << endl;
	LinkedList::printList(listHead);
	
	delete[] testArray;
	delete[] testCommands;
	delete[] onlyOddElements;
}
