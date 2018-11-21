#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>

#include <cstdlib>
#include <iostream> // cin, cout, endl
#include <locale>   // setlocale(LC_ALL, "Russian")

#include "../testFixture/LinkedListFixture.h"
#include "../tasks/task-51-linked-list.h"

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
	const int arrayLength = 10;
	auto *testArray = new int[arrayLength]{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	ListFixture::insertTestValues(testArray, arrayLength);
	
	qsort(testArray, arrayLength, sizeof(int), compare);
	
	// ::testing::AssertionSuccess() <=> true
	ASSERT_TRUE(ListFixture::checkList(testArray, arrayLength));
	
	cout << endl;
	LinkedList::printList(listHead);
	
	delete[] testArray;
}


TEST_F(ListFixture, dialogLoopTest)
{
	// Enable Russian in console
	setlocale(LC_ALL, "Russian");
	
	const int arrayLength = 10;
	auto *testArray = new int[arrayLength]{1, 1, 1, 2, 1, 3, 1, 4, 3, 0};
	
	cout << "\n\t\t<=== Начать тестирование последовательности комманд ===>" << endl;
	testDialogLoop(testArray, arrayLength);
	
	cout << "Длина списка: " << LinkedList::length(listHead);
	ASSERT_EQ(LinkedList::length(listHead), 4);
	
	SUCCEED();
	delete[] testArray;
}
