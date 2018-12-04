#include "../tasks/JosephusProblem/task-52-circular-linked-list.h"
#include "CircularListFixture.h"
#include <iostream>


using namespace std;


void CircularListFixture::createListOfSoldiers(int quantity)
{
	for (int i = 2; i <= quantity; ++i)
	{
		theList->insert(i);
	}
	
	cout << "\nTesting list was set:" << endl;
	theList->print();
}


// A little remark:
// In the novel Treasure Island by Robert Louis Stevenson,
// pirates are presented with a "black spot" to officially pronounce a verdict of guilt or judgement.
int CircularListFixture::JosephusCount(const int blackSpot)
{
	// Default value of counter = 2
	// because we start counting from soldier with number 'headValue + 1'.
	// And headValue is always = 1.
	int counter = 2;
	
	auto *previous = theList->listHead;
	auto *current = theList->listHead->getNext();
	
	while (theList->length() > 1)
	{
		if (counter == blackSpot)
		{
			cout << "\nR.I.P. soldier N: " << current->getData() << endl;
			previous->setNext(current->getNext());
			
			if (theList->isHead(current))
			{
				theList->listHead = current->getNext();
			}
			
			delete current;
			counter = 0;
		}
		else
		{
			previous = current;
			current = current->getNext();
			++counter;
		};
	}
	
	// current length of the list is 1
	theList->listHead = current->getNext();
	theList->listHead->setNext(current->getNext());
	
	cout << "\nSoldier with number: " << theList->listHead->getData() << " survived!" << endl;
	
	// save number
	survived = theList->listHead->getData();
}


::testing::AssertionResult CircularListFixture::insertTest(int value, int expectedLength)
{
	theList->insert(value);
	theList->print();
	return (expectedLength == theList->length()) ?
	       ::testing::AssertionSuccess() : ::testing::AssertionFailure();
}


::testing::AssertionResult CircularListFixture::killTest(int value, int expectedLength)
{
	theList->kill(value);
	theList->print();
	return (expectedLength == theList->length()) ?
	       ::testing::AssertionSuccess() : ::testing::AssertionFailure();
}
