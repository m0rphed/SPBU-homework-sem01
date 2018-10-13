#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h> // Google Mock. Google Mock works seamlessly with Google Test.

#include <stdio.h>       // puts()
#include <stdlib.h>      // qsort(), srand()

// using arrayHelpers.h for more efficient array initialization etc.
#include "../problemsets/problemset-02/arrayHelpers.h"

// include all solutions from problemset-02
#include "../problemsets/problemset-02/task-21-fibonacci.h"
#include "../problemsets/problemset-02/task-22-power.h"
#include "../problemsets/problemset-02/task-23-counting-bubbles.h"
#include "../problemsets/problemset-02/task-24-sort-rand-array.h"


::testing::AssertionResult strangeSortTestFunc(int *testArray, const int size)
{
	bool success = true;
	
	for (int i = 2; i < size; i++)
	{
		if (testArray[i - 1] >= testArray[0])
		{
			if (testArray[i] < testArray[0])
			{
				success = false;
			}
		}
	}
	
	if (success)
	{
		return ::testing::AssertionSuccess();
	}
	else
	{
		return ::testing::AssertionFailure();
	}
}


TEST(fibonacciTest, basicTests)
{
	// The first value of the pair — the number of the element of the Fibonacci sequence.
	// The second value of the pair — expected value.
	const int testValues[][2] = {{1,  1},
	                             {2,  1},
	                             {10, 55},
	                             {37, 24157817},
	                             {45, 1134903170}};
	
	for (const auto valuePair : testValues)
	{
		// Test different implementations
		ASSERT_EQ(valuePair[1], recursiveFib(valuePair[0]));
		ASSERT_EQ(valuePair[1], iterativeFib(valuePair[0]));
		ASSERT_EQ(valuePair[1], analyticFib(valuePair[0]));
		ASSERT_EQ(valuePair[1], matrixFib(valuePair[0]));
	}
	
	puts("\n\tAll tests for task 'fibonacci' -- passed!\n");
}


TEST(raisedToThePowerTest, basicTests)
{
	int powerValues[] = {0, 1, 9, 10};
	int testValues[] = {0, -1, 1, -2, 2, -3, 3};
	
	// Let's do some tests!
	for (const auto testCase : testValues)
	{
		for (const auto power: powerValues)
		{
			ASSERT_EQ(pow(testCase, power), binaryPow(testCase, power));
			ASSERT_EQ(pow(testCase, power), simplePow(testCase, power));
		}
	}
	puts("\n\tAll tests for task 'power' -- passed!\n");
}


TEST(bubbleSortTest, randomArrayTests)
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


TEST(countingSortTest, randomArrTest)
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


TEST(strangeSort, randomArraysTest)
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
<<<<<<< HEAD:problemset-02/run_unit_tests.cpp
}


int main(int argc, char **argv)
{
	// inti gtest framework
	testing::InitGoogleTest(&argc, argv);
	
	// Force print tests times
	testing::GTEST_FLAG(print_time) = true;
	
	puts("\nRunning main() from run_unit_test.cpp\n");
	
	return RUN_ALL_TESTS();
}
=======
}
>>>>>>> overload-v2.0:unit-tests/utest-pset-2.cpp
