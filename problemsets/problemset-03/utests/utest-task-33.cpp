#include "../tasks/task-33-most-frequent-element.h"
#include "../../HelperFunctions/arrayHelpers.h"

#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>

#include <iostream>

using namespace std;


TEST(problemset03, findFrequentSilly)
{
	const int size = 10;
	const int maxArrayValue = 10;
	
	auto *testArr = new int[size]{1, 2, 6, 2, 3, 2, 2, 2, 3, 4};
	auto *frequency = new int[maxArrayValue]{};
	
	EXPECT_EQ(2, sillySolution::findMostFrequent(testArr, frequency, size));
	
	delete[] testArr;
	delete[] frequency;
	
	std::cout << "\n\tTests for function sillySolution::findMostFrequent() -- passed!" << std::endl;
}


TEST(problemset03, findFrequentSmart)
{
	const int size = 10;
	
	auto *testArray = new int[size]{2, 2, 2, 1, 3, 4, 4, 2, 4, 4};
	EXPECT_EQ(2, smartSolution::findMostFrequent(testArray, size));
	delete[] testArray;
	
	testArray = new int[size]{0, 4, 4, 4, 4, 5, 5, 5, 5, 5};
	ASSERT_EQ(5, smartSolution::findMostFrequent(testArray, size));
	delete[] testArray;
	
	std::cout << "\n\tTests for function smartSolution::findMostFrequent() -- passed!" << std::endl;
}
