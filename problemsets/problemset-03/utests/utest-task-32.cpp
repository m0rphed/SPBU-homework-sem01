#include "../tasks/task-32-quick-binary-search.h"

#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>


TEST(problemset03, primeNumbersGangWantedDeadOrAlive)
{
	const int n = 25;
	const int k = 100;
	
	int primes[n] = {
			2, 3, 5, 7, 11,
			13, 17, 19, 23, 29,
			31, 37, 41, 43, 47,
			53, 59, 61, 67, 71,
			73, 79, 83, 89, 97
	};
	
	// test-array
	int numbers[k] = {};
	
	// initialize test-array with with natural series
	for (int i = 0; i < k; ++i)
	{
		numbers[i] = i + 1;
	}
	
	// expected result
	bool expectedMatches[k] = {};
	
	// initialize prime numbers positions with 'true' values
	for (auto &prime : primes)
	{
		expectedMatches[prime-1] = true;
	}
	
	// array keeps search results
	bool foundMatches[k] = {};
	qBinarySearch(primes, n, numbers, k, foundMatches);
	
	for (int i = 0; i < k; ++i)
	{
		ASSERT_EQ(foundMatches[i], expectedMatches[i]);
	}
}