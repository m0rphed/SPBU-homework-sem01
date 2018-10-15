#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h> // Google Mock. Google Mock works seamlessly with Google Test.

#include <stdio.h>       // puts()

// include solution from problemset-02
#include "../problemsets/problemset-02/task-22-power.h"


TEST(problemset02, raisedToThePowerTest)
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
