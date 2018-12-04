#include "josephusProblem.h"
#include "CircularLinkedList.h"
#include <iostream>


// A little remark:
// In the novel Treasure Island by Robert Louis Stevenson,
// pirates are presented with a "black spot" to officially pronounce a verdict of guilt or judgement.
int josephusCount(CircularList::LinkedList *soldiers, const int &blackSpot)
{
	using namespace std;
	
	// Default value of counter = 2
	// because we start counting from soldier with number 'headValue + 1'.
	// And headValue is always = 1.
	int counter = 2;
	
	auto *previous = soldiers->listHead;
	auto *current = soldiers->listHead->getNext();
	
	while (soldiers->length() > 1)
	{
		if (counter == blackSpot)
		{
			cout << "\nR.I.P. soldier N: " << current->getData() << endl;
			previous->setNext(current->getNext());
			
			if (soldiers->isHead(current))
			{
				soldiers->listHead = current->getNext();
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
	soldiers->listHead = current->getNext();
	soldiers->listHead->setNext(current->getNext());
	
	cout << "\nSoldier with number: " << soldiers->listHead->getData() << " survived!" << endl;
}
