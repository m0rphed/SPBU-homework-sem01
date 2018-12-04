#include "../tasks/JosephusProblem/CircularLinkedList.h"
#include "CircularListFixture.h"
#include <iostream>


using namespace std;


void CircularListFixture::createListOfSoldiers(int quantity)
{
	for (int i = 2; i <= quantity; ++i)
	{
		testList->insert(i);
	}
	
	cout << "\nTesting list was set:" << endl;
	testList->print();
}


::testing::AssertionResult CircularListFixture::insertTest(int value, int expectedLength)
{
	testList->insert(value);
	testList->print();
	return (expectedLength == testList->length()) ?
	       ::testing::AssertionSuccess() : ::testing::AssertionFailure();
}


::testing::AssertionResult CircularListFixture::killTest(int value, int expectedLength)
{
	testList->kill(value);
	testList->print();
	return (expectedLength == testList->length()) ?
	       ::testing::AssertionSuccess() : ::testing::AssertionFailure();
}
