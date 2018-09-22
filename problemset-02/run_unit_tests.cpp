#include <stdio.h>
#include <gtest/gtest.h> // Google Test Framework

// include all solutions from problemset-02
#include "01_fibonacci.cpp"
#include "02_power.cpp"
#include "03_counting_bubbles.cpp"
#include "04_sort_rand_array.cpp"


TEST(FibonacciTest, Num37)
{
	const int fibNum37 = 24157817;
	ASSERT_EQ(fibNum37, recursiveFib(0, 1, 37));
	ASSERT_EQ(fibNum37, iterativeFib(37));
	ASSERT_EQ(fibNum37, analyticFib(37));
	
	puts("\n\tAll tests for task 'Fibonacci' -- passed!\n");
}

int main(int argc, char **argv)
{
	// inti gtest framework
	testing::InitGoogleTest(&argc, argv);
	
	// Force print tests times
	testing::GTEST_FLAG(print_time) = true;
	
	puts("Running main() from run_unit_test.cc\n");
	
	return RUN_ALL_TESTS();
}
