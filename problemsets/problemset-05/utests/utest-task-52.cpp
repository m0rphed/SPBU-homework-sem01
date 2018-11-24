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
	cout << "\n\n<=== Start testing: task-5.2 --> CircularListStructureTest ===>" << endl;
	
	auto *myList = new CircularList::LinkedList(4);
	cout << endl;
	cout << "Length: " << myList->length() << endl;
	
	myList->print();
	myList->insert(1);
	myList->insert(2);
	myList->insert(3);
	myList->insert(4);
	
	myList->print();

	myList->kill(1);
	myList->print();
	
	myList->kill(4);
	myList->print();
	
	myList->kill(4);
	myList->print();
	
	myList->kill(2);
	myList->print();
	
	delete myList;
	SUCCEED();
}