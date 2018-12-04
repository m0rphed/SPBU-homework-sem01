#pragma once

#include "../tasks/JosephusProblem/task-52-circular-linked-list.h"
#include <gtest/gtest.h>


// Abstract Test Class <=> Test Fixture
class CircularListFixture : public ::testing::Test
{
public:
	
	int survived = 0;
	
	void createListOfSoldiers(int quantity);
	
	int JosephusCount(int blackSpot);
	
	::testing::AssertionResult insertTest(int value, int expectedLength);
	
	::testing::AssertionResult killTest(int value, int expectedLength);

protected:
	
	CircularList::LinkedList *theList = nullptr;
	
	// Standard fixture constructor
	virtual void SetUp()
	{
		theList = new CircularList::LinkedList(1);
	}
	
	// Standard fixture destructor
	virtual void TearDown()
	{
		delete theList;
	}
};