#include "../tasks/SetOnBinTree/Set.h"
#include "../tasks/SetOnBinTree/task-71-userInterface.h"

#include <gtest/gtest.h> // Google Test Framework
#include <iostream>


TEST(problemset07, task71)
{
	using namespace std;
	
	auto *mySet = new Set();
	
	ASSERT_TRUE(mySet->isEmpty());
	
	for (int i = 0; i < 10; ++i)
	{
		mySet->addValue(i);
	}
	
	EXPECT_FALSE(mySet->isEmpty());
	
	for (int i = 0; i < 10; ++i)
	{
		EXPECT_TRUE(mySet->contains(i));
	}
	
	for (int i = 0; i < 10; ++i)
	{
		EXPECT_FALSE(mySet->addValue(i));
	}
	
	cout << "\nAll tests passed" << endl;
}
