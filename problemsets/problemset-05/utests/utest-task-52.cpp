#include "../tasks/JosephusProblem/task-52-circular-linked-list.h"
#include "../testFixtures/CircularListFixture.h"

#include <gtest/gtest.h> // Google Test Framework

using namespace std;


TEST_F(CircularListFixture, JosephusSetUpTest)
{
	cout << "\n\n<=== Start testing: task-5.2-JosephusProblemStandardTest ===>" << endl;
	
	const int n = 13;
	const int m = 2;
	
	this->createListOfSoldiers(n);
	this->JosephusCount(m);
	
	SUCCEED();
}

TEST_F(CircularListFixture, JosephusSetUpTest2)
{
	cout << "\n\n<=== Start testing: task-5.2 --> test2 ===>" << endl;
	
	const int n = 41;
	const int m = 2;
	
	this->createListOfSoldiers(n);
	this->JosephusCount(m);
	
	SUCCEED();
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
	ASSERT_EQ(666, myList->listHead->data);
	
	myList->insert(555);
	ASSERT_EQ(2, myList->length());
	myList->print();
	
	myList->kill(666);
	ASSERT_EQ(1, myList->length());
	myList->print();
	
	myList->insert(555);
	ASSERT_EQ(2, myList->length());
	myList->print();
	
	myList->insert(777);
	ASSERT_EQ(3, myList->length());
	ASSERT_EQ(555, myList->listHead->data);
	myList->print();
	
	myList->kill(555);
	ASSERT_EQ(2, myList->length());
	
	delete myList;
}