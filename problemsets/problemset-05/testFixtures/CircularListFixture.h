#pragma once

#include "../tasks/JosephusProblem/CircularLinkedList.h"
#include "../tasks/JosephusProblem/josephusProblem.h"
#include <gtest/gtest.h>


// Abstract Test Class <=> Test Fixture
class CircularListFixture : public ::testing::Test
{
public:
	
	int survived = 0;
	
	void createListOfSoldiers(int quantity);
	
	::testing::AssertionResult insertTest(int value, int expectedLength);
	
	::testing::AssertionResult killTest(int value, int expectedLength);

protected:
	
	CircularList::LinkedList *testList = nullptr;
	
	// Standard fixture constructor
	virtual void SetUp()
	{
		testList = new CircularList::LinkedList(1);
	}
	
	// Standard fixture destructor
	virtual void TearDown()
	{
		delete testList;
	}
};