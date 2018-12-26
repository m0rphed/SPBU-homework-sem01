#include "../tasks/task-42-searchInFile/mostFrequentElement.h"
#include "../tasks/task-42-searchInFile/handleInput.h"

#include <stdio.h>

#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>


TEST(problemset04, searchInFileSimpleTest)
{
	printf("\n\n\t-------------- Start testing task-4.2 --------------\n\n");
	const int size = 50;
	
	auto *testArray = new int[size]{};
	
	char fileName[] = "./tasks/task-42-searchInFile/data.txt";
	
	getInputFromFile(testArray, size, fileName);
	
	ASSERT_EQ(8, findMostFrequent(testArray, size));
	printf("\nThe most frequent element in the file: %d\n", findMostFrequent(testArray, size));
	delete[] testArray;
}
