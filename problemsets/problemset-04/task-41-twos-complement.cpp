#include "task-41-twos-complement.h"

#include <stdio.h>
#include <math.h>
#include <locale.h>


// Function provides input from console
void getNumberFromConsole(int &value)
{
	printf("\nВведите целое число:\n");
	scanf("%d", &value);
}


// Function returns a bit mask for a number
unsigned int getBitMask(const int number)
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


void printBinary(Number *n)
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


void initializeNumber(Number *n, int decimalValue)
{
	n->value = decimalValue;
	n->mask = getBitMask(n->value);
}


int main()
{
	// Allow Russian in I/O.
	setlocale(LC_ALL, "Russian");
	
	int inputValue = 0;
	
	Number first;
	getNumberFromConsole(inputValue);
	initializeNumber(&first, inputValue);
	printf("\n %d в двоичном представлениии:\n", first.value);
	printBinary(&first);
	
	Number second;
	getNumberFromConsole(inputValue);
	initializeNumber(&second, inputValue);
	printf("\n %d в двоичном представлениии:\n", second.value);
	printBinary(&second);
	
	Number sum;
	initializeNumber(&sum, first.value + second.value);
	printf("\nCумма в двоичном представлениии:gi\n");
	printBinary(&sum);
	
	printf("\nCумма в десятичном представлениии:\n%d\n", sum.value);
	return 0;
}
