#include "NumberFixture.h"
// Include task-4.1
#include "../tasks/task-41-bitwiseOperations/task-41-bitwise-operations.h"

#include <gtest/gtest.h>
#include <iostream>


using namespace std;


void NumberFixture::setNumberPair(int firstValue, int secondValue)
{
	// Assign values for both numbers, and for the Sum
	firstNumber->value = firstValue;
	secondNumber->value = secondValue;
	Sum->value = firstValue + secondValue;
	
	// Generate masks for both numbers, and for the Sum
	firstNumber->mask = bitwise::genBitMask(firstValue);
	secondNumber->mask = bitwise::genBitMask(secondValue);
	Sum->mask = bitwise::genBitMask(firstValue + secondValue);
}


void NumberFixture::printNumbersInfo()
{
	cout << "\nЧисло " << firstNumber->value << " в двоичном представлениии:" << endl;
	bitwise::printBinary(firstNumber);
	
	cout << "\nЧисло " << secondNumber->value << " в двоичном представлениии:" << endl;
	bitwise::printBinary(secondNumber);
	
}


void NumberFixture::printNumbersSum()
{
	cout << "\nСумма в двоичном представлениии:" << endl;
	printBinary(Sum);
	
	cout << "\nСумма в десятичном представлениии:" << endl;
	cout << Sum->value << endl;
	
}
