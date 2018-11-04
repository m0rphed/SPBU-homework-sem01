#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>

// using arrayHelpers.h for more efficient array initialization etc.
#include "../problemsets/problemset-02/arrayHelpers.h"

// include solution from problemset-03
#include "../problemsets/problemset-03/task-31-quicksort.h"


::testing::AssertionResult isAscendingArray(int *testArray, const int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (testArray[i] < testArray[i - 1])
		{
			return ::testing::AssertionFailure();
		}
	}
	return ::testing::AssertionSuccess();
}


TEST(problemset03, quickSortTest)
{
	// use current time as seed for random generator
	srand(time(nullptr));
	
	// set the size of arrays
	const int size = 15;
	const int lastIndex = size - 1;
	
	// set the number of tests
	const int numOfTests = 5;
	
	int testArrays[numOfTests][size] = {};
	
	for (auto array : testArrays)
	{
		fillArray(array, size);
	}
	
	for (auto array : testArrays)
	{
		quickSort(array, 0, lastIndex);
		EXPECT_TRUE(isAscendingArray(array, size));
	}
	
	puts("\n\tAll tests for function 'quickSort' -- passed!\n");
}

TEST(problemset03, insertionSortTest)
{
	// use current time as seed for random generator
	srand(time(nullptr));
	
	// set the size of arrays
	const int size = 10;
	
	// set the number of tests
	const int numOfTests = 5;
	
	int testArrays[numOfTests][size] = {};
	
	for (auto array : testArrays)
	{
		fillArray(array, size);
	}
	
	for (auto array : testArrays)
	{
		insertionSort(array, size);
		EXPECT_TRUE(isAscendingArray(array, size));
	}
	
	puts("\n\tAll tests for function 'insertionSort' -- passed!\n");
}