#pragma once


#include "../tasks/JosephusProblem/task-52-circular-linked-list.h"
#include <gtest/gtest.h>


// Abstract Test Class <=> Test Fixture
class CircularListFixture : public ::testing::Test
{
public:
	
	void createListOfSoldiers(int quantity);
	
	::testing::AssertionResult checkListStructure();

protected:
	
	// Standard fixture constructor
	virtual void SetUp()
	{
		testingList = new CircularList::LinkedList(1);
	}
	
	// Standard fixture destructor
	virtual void TearDown()
	{
		delete testingList;
	}
	
	CircularList::LinkedList *testingList = nullptr;
};