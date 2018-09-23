#include <stdio.h>
#include <gtest/gtest.h> // Google Test Framework

// include all solutions from problemset-02
#include "01_fibonacci.cpp"
#include "02_power.cpp"
#include "03_counting_bubbles.cpp"
#include "04_sort_rand_array.cpp"


TEST(FibonacciTest, BasicTests)
{
	const int fib_1 = 1;
	ASSERT_EQ(fib_1, recursiveFib(0, 1, 1));
	ASSERT_EQ(fib_1, iterativeFib(1));
	ASSERT_EQ(fib_1, analyticFib(1));
	
	const int fib_2 = 1;
	ASSERT_EQ(fib_2, recursiveFib(0, 1, 2));
	ASSERT_EQ(fib_2, iterativeFib(2));
	ASSERT_EQ(fib_2, analyticFib(2));
	
	const int fib_10 = 55;
	ASSERT_EQ(fib_10, recursiveFib(0, 1, 10));
	ASSERT_EQ(fib_10, iterativeFib(10));
	ASSERT_EQ(fib_10, analyticFib(10));
	
	const int fib_37 = 24157817;
	ASSERT_EQ(fib_37, recursiveFib(0, 1, 37));
	ASSERT_EQ(fib_37, iterativeFib(37));
	ASSERT_EQ(fib_37, analyticFib(37));
	
	const int fib_45 = 1134903170;
	ASSERT_EQ(fib_45, recursiveFib(0, 1, 45));
	ASSERT_EQ(fib_45, iterativeFib(45));
	ASSERT_EQ(fib_45, analyticFib(45));
	
	puts("\n\tAll tests for task 'fibonacci' -- passed!\n");
}

TEST(RaisedToThePowerTest, BinaryPow)
{
	const int evenPower = 10;
	const int oddPower = 9;
	
	const int zero = 0;
	ASSERT_EQ(1, binaryPow(zero, 0));
	ASSERT_EQ(zero, binaryPow(zero, 1));
	ASSERT_EQ(zero, binaryPow(zero, evenPower));
	ASSERT_EQ(zero, binaryPow(zero, oddPower));
	
	ASSERT_EQ(1, binaryPow(2, 0));
	ASSERT_EQ(2, binaryPow(2, 1));
	ASSERT_EQ(1024, binaryPow(2, evenPower));
	ASSERT_EQ(512, binaryPow(2, oddPower));
	
	ASSERT_EQ(1, binaryPow(-2, 0));
	ASSERT_EQ(-2, binaryPow(-2, 1));
	ASSERT_EQ(1024, binaryPow(-2, evenPower));
	ASSERT_EQ(-512, binaryPow(-2, oddPower));
	
	puts("\n\tAll tests for function 'binaryPow' -- passed!\n");
}

TEST(RaisedToThePowerTest, SimplePow)
{
	const int evenPower = 10;
	const int oddPower = 9;
	
	const int zero = 0;
	ASSERT_EQ(1, simplePow(zero, 0));
	ASSERT_EQ(zero, simplePow(zero, 1));
	ASSERT_EQ(zero, simplePow(zero, evenPower));
	ASSERT_EQ(zero, simplePow(zero, oddPower));
	
	ASSERT_EQ(1, simplePow(2, 0));
	ASSERT_EQ(2, simplePow(2, 1));
	ASSERT_EQ(1024, simplePow(2, evenPower));
	ASSERT_EQ(512, simplePow(2, oddPower));
	
	ASSERT_EQ(1, simplePow(-2, 0));
	ASSERT_EQ(-2, simplePow(-2, 1));
	ASSERT_EQ(1024, simplePow(-2, evenPower));
	ASSERT_EQ(-512, simplePow(-2, oddPower));
	
	puts("\n\tAll tests for function 'simplePow' -- passed!\n");
}


int main(int argc, char **argv)
{
	// inti gtest framework
	testing::InitGoogleTest(&argc, argv);
	
	// Force print tests times
	testing::GTEST_FLAG(print_time) = true;
	
	puts("\nRunning main() from run_unit_test.cc\n");
	
	return RUN_ALL_TESTS();
}
