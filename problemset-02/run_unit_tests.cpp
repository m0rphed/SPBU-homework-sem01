#include <stdio.h>
#include <gtest/gtest.h> // Google Test Framework

// include all solutions from problemset-02
#include "01_fibonacci.cpp"
#include "02_power.cpp"


TEST(fibonacciTest, basicTests)
{
	// The first value of the pair — the number of the element of the Fibonacci sequence.
	// The second value of the pair — expected value.
	const int testValues[][2] = {{1,  1},
	                             {2,  1},
	                             {10, 55},
	                             {37, 24157817},
	                             {45, 1134903170}};
	
	for (auto valuePair : testValues)
	{
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
	for (auto testCase : testValues)
	{
		for (auto power: powerValues)
		{
			ASSERT_EQ(pow(testCase, power), binaryPow(testCase, power));
			ASSERT_EQ(pow(testCase, power), simplePow(testCase, power));
		}
	}
	puts("\n\tAll tests for task 'power' -- passed!\n");
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