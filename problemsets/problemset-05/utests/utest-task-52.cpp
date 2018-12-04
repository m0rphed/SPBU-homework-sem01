#include "../tasks/JosephusProblem/CircularLinkedList.h"
#include "../testFixtures/CircularListFixture.h"

#include <gtest/gtest.h> // Google Test Framework

using namespace std;


TEST_F(CircularListFixture, JosephusSetUpTest)
{
	cout << "\n\n<=== Start testing: task-5.2-JosephusProblemStandardTest ===>" << endl;
	
	const int n = 13;
	const int m = 2;
	
	this->createListOfSoldiers(n);
	
	josephusCount(testList, m);
	
	// save number
	survived = testList->listHead->getData();
	
	ASSERT_EQ(11, this->survived);
}


TEST_F(CircularListFixture, JosephusSetUpTest2)
{
	cout << "\n\n<=== Start testing: task-5.2 --> test2 ===>" << endl;
	
	const int n = 41;
	const int m = 2;
	
	this->createListOfSoldiers(n);
	josephusCount(testList, m);
	
	// save number
	survived = testList->listHead->getData();
	
	
	ASSERT_EQ(19, this->survived);
}


TEST_F(CircularListFixture, insertThenKill)
{
	cout << "\n\n<=== Start testing: insertThenKillTest ===>" << endl;
	
	const int n = 41;
	const int m = 2;
	
	this->createListOfSoldiers(n);
	
	cout << "\nInsert: " << 42 << endl;
	this->insertTest(42, testList->length() + 1);
	
	cout << "\nKill: " << 1 << endl;
	this->killTest(1, testList->length() - 1);
	
	josephusCount(testList, m);
	
	// save number
	survived = testList->listHead->getData();
	
	ASSERT_EQ(20, survived);
}


TEST(problemset05, circularListTest)
{
	cout << "\n\n<=== Start testing: task-5.2 -- testing list interface ===>" << endl;
	
	auto *myList = new CircularList::LinkedList(666);
	
	cout << "\nLength: " << myList->length() << endl;
	ASSERT_EQ(1, myList->length());
	
	const int N = 10;
	const int testValues[N] = {1, 2, 3, 10, -23, 44, 0, 0, 0, 0};
	
	for (const auto &value : testValues)
	{
		myList->insert(value);
	}
	
	cout << "\nInsert some elements to the list" << endl;
	myList->print();
	
	for (const auto &value : testValues)
	{
		myList->kill(value);
	}
	
	myList->print();
	
	ASSERT_EQ(1, myList->length());
	ASSERT_EQ(666, myList->listHead->getData());
	
	delete myList;
}