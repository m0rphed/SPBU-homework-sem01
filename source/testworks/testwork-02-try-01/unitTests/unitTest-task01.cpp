#include "../task01.h"
#include "../dataStructures.h"
#include <gtest/gtest.h> // Google Test Framework
#include <iostream>


TEST(testWork2_0, task_01)
{
	const int size = 10;
	auto *testArray = new int[size];
	
	std::cout << std::endl;
	for (int i = 0; i < size; ++i)
	{
		testArray[i] = i;
		std::cout << testArray[i] << " ";
	}
	
	std::cout << std::endl;
	auto *testList = new MyLinkedList(testArray, size);
	
	std::cout << "List before reversing:" << std::endl;
	testList->printList();
	
	std::cout << "List after reversing:" << std::endl;
	testList->reverse();
	testList->printList();
	
	auto *copyOfHead = testList->getHead();
	
	for (int i = size - 1; i >= 0; --i)
	{
		ASSERT_EQ(copyOfHead->data, i);
		copyOfHead = copyOfHead->next;
	}
}
