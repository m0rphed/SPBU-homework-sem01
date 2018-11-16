#pragma once

namespace magicNumber
{
	// struct -- should not be here,
	// but there is no other way :(
	// otherwise GCC just don't want to compile this
	struct Number
	{
		int value;
		unsigned int mask;
		
		Number(int v, unsigned int m) : value(v), mask(m)
		{
		}
	};
	
	
	void getInput(int &inputNumber, bool isAutomatic = false, int value = 0);
	
	
	unsigned int getBitMask(int number);
	
	
	void printBinary(Number *n);
}
