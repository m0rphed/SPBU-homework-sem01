#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>
#include <iostream>
#include "../tasks/AbstractDataType-Set/Set.h"
#include "../tasks/AbstractDataType-Set/task-71-set.h"

TEST(problemset07, task71)
{
	using namespace std;
	
	auto *mySet = new Set();
	
	ASSERT_TRUE(mySet->isEmpty());
	
	for (int i = 0; i < 10; ++i)
	{
		mySet->add(i);
	}
	
	EXPECT_FALSE(mySet->isEmpty());
	
	for (int i = 0; i < 10; ++i)
	{
		EXPECT_TRUE(mySet->isExists(i));
	}
	
	for (int i = 0; i < 10; ++i)
	{
		EXPECT_FALSE(mySet->add(i));
	}
	
	cout << "All tests passed" << endl;
}
