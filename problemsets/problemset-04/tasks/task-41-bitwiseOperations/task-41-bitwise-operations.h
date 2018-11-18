#pragma once

namespace bitwise
{
	// Defines special type <Number>.
	// Any element of <Number> stores a 'value', and 'mask'
	// Binary representation of 'value' could be printed using 'mask'
	struct Number
	{
		int value;
		unsigned int mask;
		
		Number(int v, unsigned int m) : value(v), mask(m)
		{
		}
	};
	
	// Func. generates binary mask for number
	unsigned int genBitMask(int number);
	
	// Func. prints binary value of number
	void printBinary(Number *number);
	
	// Func. handles user input
	void getInput(int &inputNumber);
}
