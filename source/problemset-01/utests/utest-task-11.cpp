#include "../tasks/task-11-polynomial.h" // header file for solution

#include <gtest/gtest.h> // Google Test Framework

// Just a simple google-test example:
TEST(problemset01, polynomialTest)
{
	const int numberOfTests = 5;
	
	float arguments[numberOfTests] = {1.0, 2.0, 3.0, 4.0, 5.0};
	float expected[numberOfTests] = {5.0, 31.0, 121.0, 341.0, 781.0};
	
	for (unsigned i = 0; i < sizeof(arguments) / sizeof(float); ++i)
	{
		EXPECT_EQ(polynomial(arguments[i]), expected[i]);
	}
	
	printf("\npolynomialTest passed!\n");
}