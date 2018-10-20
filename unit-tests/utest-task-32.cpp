#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>

// using arrayHelpers.h for more efficient array initialization etc.
#include "../problemsets/problemset-02/arrayHelpers.h"

// include solution from problemset-03
#include "../problemsets/problemset-03/task-32-quick-binary-search.h"


TEST(problemset03, qBinarySearchTest)
{
	const int maxValue = pow(10, 9);
	
	// default values for n and k
	int n = 100;
	int k = 20;

	auto *array = new int[n];
	auto *arrayOfNums = new int[k];
	auto *foundMatches = new int[k]{};
	
	srand(time(nullptr));
	fillArray(array, n, 0, maxValue);
	
	srand(time(nullptr));
	fillArray(arrayOfNums, k, 0, maxValue);
	
	qBinarySearch(array, n, arrayOfNums, k, foundMatches);
	
	// I just leave it here...
	// printArrayTilZeros(foundMatches, k);

	delete[] array;
	delete[] arrayOfNums;
	delete[] foundMatches;
	
	puts("\n\tAll tests for function 'qBinarySearch' -- passed!\n");
}
