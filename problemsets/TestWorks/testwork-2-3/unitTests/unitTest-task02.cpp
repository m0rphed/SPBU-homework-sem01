#include "../task02.h"
#include "../dataStructures.h"

#include <gtest/gtest.h> // Google Test Framework

using namespace std;

TEST(testwork2ThirdTry, doublyListInterface)
{
	auto *testList = new DoublyLinkedList();
	
	for (int i = 0; i < 20; i++)
	{
		testList->addTo(i, i);
	}
	
	cout << "Elements in the list:" << endl;
	testList->print();
	
	cout << "Elements in the list (in reversed order):" << endl;
	testList->printReverse();
	
	ASSERT_EQ(testList->getLength(), 20);
	ASSERT_EQ((testList->getHead())->data, 0);
	ASSERT_EQ((testList->getTail())->data, 19);
	
	for (int i = 0; i < 20; i++)
	{
		EXPECT_EQ((testList->getNodeAt(i))->data, i);
	}
	
	cout << endl;
}