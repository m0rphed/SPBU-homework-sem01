#include "task-41-bitwise-operations.h"

#include <iostream>


// Function handles console input
void bitwise::getInput(int &inputNumber)
{
	std::cout << "\nВведите целое число:" << std::endl;
	std::cin >> inputNumber;
}


// Function returns a bit mask for a number
unsigned int bitwise::genBitMask(const int number)
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


void bitwise::printBinary(Number *number)
{
	// Make a copy of bit mask
	unsigned int mask = number->mask;
	
	while (mask)
	{
		printf((number->value & mask) ? "1" : "0");
		mask >>= 1;
	}
	printf("\n");
}
