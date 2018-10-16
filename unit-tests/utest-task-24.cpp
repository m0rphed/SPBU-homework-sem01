#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h> // Google Mock. Google Mock works seamlessly with Google Test.

#include <time.h>        // time()
#include <stdio.h>       // puts()
#include <stdlib.h>      // srand()

// using arrayHelpers.h for more efficient array initialization etc.
#include "../problemsets/problemset-02/arrayHelpers.h"

// include solution from problemset-02
#include "../problemsets/problemset-02/task-24-sort-rand-array.h"


::testing::AssertionResult strangeSortTestFunc(int *testArray, const int size)
{
	for (int i = 2; i < size; i++)
	{
		if (testArray[i - 1] >= testArray[0])
		{
			if (testArray[i] < testArray[0])
			{
				return ::testing::AssertionFailure();
			}
		}
	}
	return ::testing::AssertionSuccess();
}


TEST(problemset02, strangeSortTest)
{
	// use current time as seed for random generator
	srand(time(nullptr));
	
	// set the size of arrays
	const int size = 15;
	
	// set the number of tests
	const int numOfTests = 5;
	
	int testArrays[numOfTests][size] = {};
	
	for (auto array : testArrays)
	{
		fillArray(array, size);
	}
	
	for (auto array : testArrays)
	{
		strangeSort(array, size);
		EXPECT_TRUE(strangeSortTestFunc(array, size));
	}
	
	puts("\n\tAll tests for task 'strangeSort' -- passed!\n");
}
