#include "task-41-twos-complement.h"

#include <math.h>
#include <iostream>
#include <locale>

using namespace std;


// Function handles console input
void magicNumber::getInput(int &inputNumber, bool isAutomatic, int value)
{
	if (isAutomatic)
	{
		inputNumber = value;
		cout << "\nАвтоматически введено целое число: " << value << endl;
	}
	else
	{
		cout << "\nВведите целое число:" << endl;
		cin >> inputNumber;
		
	}
}


// Function returns a bit mask for a number
unsigned int magicNumber::getBitMask(const int number)
{
	if (number >= 0)
	{
		// One byte (8 bits) can encode 256 numbers (from 0 to 255)
		// So, default bit mask value for 1 byte: 0b10000000 = 2^7 = 128
		unsigned int mask = 0b10000000;
		
		while (number > mask * 2 - 1)
		{
			mask *= 2;
		}
		return mask;
	}
	else
	{
		// first bit keeps the sign of 32-bit number
		// for signed number mask = 2^30
		return 0b01000000000000000000000000000000;
	}
}


void magicNumber::printBinary(Number *n)
{
	// Make a copy of bit mask
	unsigned int mask = n->mask;
	
	while (mask)
	{
		printf((n->value & mask) ? "1" : "0");
		mask >>= 1;
	}
	printf("\n");
}
