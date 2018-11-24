#include "CircularListFixture.h"


::testing::AssertionResult CircularListFixture::checkListStructure()
{
}


void CircularListFixture::createListOfSoldiers(int quantity)
{
	for (int i = 2; i <= quantity; ++i)
	{
		testingList->insert(i);
	}
	
	std::cout << "\nTesting list was set:" << std::endl;
	testingList->print();
}
