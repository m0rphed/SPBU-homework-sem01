#pragma once


#include "../tasks/LinkedList/task-51-linked-list.h"
#include <gtest/gtest.h>


// Abstract Test Class <=> Test Fixture
class ListFixture : public ::testing::Test
{
public:
	
	void simulateDialogLoop(int *commands, int length);
	
	void insertTestValues(int *array, int size);
	
	::testing::AssertionResult checkList(int *array, int size);

protected:
	
	// Standard fixture constructor
	virtual void SetUp()
	{
		listHead = new LinkedList::Node(0, nullptr);
	}
	
	// Standard fixture destructor
	virtual void TearDown()
	{
		LinkedList::deleteList(listHead);
	}
	
	LinkedList::Node *listHead = nullptr;
};
