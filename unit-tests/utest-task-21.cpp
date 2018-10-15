#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h> // Google Mock. Google Mock works seamlessly with Google Test.

#include <stdio.h>       // puts()

// include solution from problemset-02
#include "../problemsets/problemset-02/task-21-fibonacci.h"


TEST(problemset02, fibonacciTest)
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
