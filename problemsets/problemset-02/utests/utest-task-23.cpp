#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h> // Google Mock. Google Mock works seamlessly with Google Test.

#include <time.h>        // time()
#include <stdio.h>       // puts()
#include <stdlib.h>      // qsort(), srand()

// using arrayHelpers.h for more efficient array initialization etc.
#include "problemset-02/tasks/arrayHelpers.h"

// include solution from problemset-02
#include "problemset-02/tasks/task-23-counting-bubbles.h"


TEST(problemset02, bubbleSortTest)
{
	
	// use current time as seed for random generator
	srand(time(nullptr));

	// set the size of arrays
	const int size = 15;

	// set the number of tests
	const int numOfTests = 5;
	
	int testArrays[numOfTests][size] = {};
	int expectedArrays[numOfTests][size] = {};
	
	for (auto testArr : testArrays)
	{
		// fill every element of testArrays with random values
		fillArray(testArr, size);
	}
	
	for (int i = 0; i < numOfTests; ++i)
	{
		copyArray(expectedArrays[i], testArrays[i], size);

		// and then sort every element using qsort()
		qsort(expectedArrays[i], size, sizeof(int), compareIncreasing);
	}
	
	for (int i = 0; i < numOfTests; ++i)
	{
		bubbleSort(testArrays[i], size);
		ASSERT_THAT(testArrays[i], testing::ElementsAreArray(expectedArrays[i]));
	}
	
	puts("\n\tAll tests for function 'bubbleSort' -- passed!\n");
}


TEST(problemset02, countingSortTest)
{
	// use current time as seed for random generator
	srand(time(nullptr));

	// set the size of arrays
	const int size = 15;

	// set the number of tests
	const int numOfTests = 5;

	// set the range for values of arrays
	const int minVal = 0;
	const int maxVal = 1000;
	
	int testArrays[numOfTests][size] = {};
	int expectedArrays[numOfTests][size] = {};
	
	for (auto testArr : testArrays)
	{
		// fill every element of testArrays with random values
		fillArray(testArr, size, minVal, maxVal);
	}
	
	for (int i = 0; i < numOfTests; ++i)
	{
		copyArray(expectedArrays[i], testArrays[i], size);

		// and then sort every element using qsort()
		qsort(expectedArrays[i], size, sizeof(int), compareIncreasing);
	}
	
	for (int i = 0; i < numOfTests; ++i)
	{
		countingSort(testArrays[i], size);
		ASSERT_THAT(testArrays[i], testing::ElementsAreArray(expectedArrays[i]));
	}
	
	puts("\n\tAll tests for function 'countingSort' -- passed!\n");
}
