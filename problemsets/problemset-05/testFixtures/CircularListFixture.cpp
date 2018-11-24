#include "../tasks/JosephusProblem/task-52-circular-linked-list.h"
#include "CircularListFixture.h"
#include "iostream"


::testing::AssertionResult CircularListFixture::checkListStructure()
{
}


void CircularListFixture::createListOfSoldiers(int quantity)
{
	for (int i = 2; i <= quantity; ++i)
	{
		theList->insert(i);
	}
	
	std::cout << "\nTesting list was set:" << std::endl;
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
	auto *current = theList->listHead->next;
	
	while (theList->length() > 1)
	{
		if (counter == blackSpot)
		{
			std::cout << "\nR.I.P. soldier N: " << current->data << std::endl;
			previous->next = current->next;
			
			if (theList->isHead(current))
			{
				theList->listHead = current->next;
			}
			
			delete current;
			counter = 0;
		}
		else
		{
			previous = current;
			current = current->next;
			++counter;
		};
	}
	
	std::cout << "Soldier with number: " << theList->listHead->data<< " survived!" << std::endl;
	std::cout << theList->listHead->data<< std::endl;
	return previous->data;
}
