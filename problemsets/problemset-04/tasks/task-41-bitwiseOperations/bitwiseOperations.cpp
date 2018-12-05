#include "bitwiseOperations.h"

#include <utility>
#include <iostream>
#include <exception>

using namespace std;

// Size of binary array is always = 32
const int size = 32;

bitwise::Number::Number(const int &value, bool *pointer)
{
	decimalValue = value;
	arrayOfBits = pointer;
}


void bitwise::Number::generateBinary()
{
	// Create new binary array
	bool *binary = new bool[size]{};
	
	binary[0] = (this->decimalValue < 0); // if decimal value is negative
	
	int bitMask = 0b01000000000000000000000000000000;
	
	for (int i = 1; i < size; ++i)
	{
		binary[i] = (this->decimalValue & bitMask);
		bitMask = bitMask >> 1;
	}
	
	// Free memory if arrayOfBits was set before
	if (!(this->arrayOfBits))
	{
		delete arrayOfBits;
	}
	
	// Save new boolean array,
	// which represents binary value of a number
	this->arrayOfBits = binary;
}


int bitwise::Number::generateDecimal()
{
	// Check if arrayOfBits is not null
	if (!(this->arrayOfBits))
	{
		cout << endl;
		cerr << "Can not generate decimal value.\n\tBinary value was not set properly.\n" << endl;
		throw "ERROR: arrayOfBits points to nullptr\n";
	}
	
	int newDecimal = 0;
	unsigned int power = 1;
	
	for (int i = size - 1; i >= 0; --i)
	{
		newDecimal += this->arrayOfBits[i] * power;
		power *= 2;
	}
	
	// Save new decimal value
	this->decimalValue = newDecimal;
}


int bitwise::Number::getActualLength()
{
	for (int i = 1; i < size; ++i)
	{
		if (this->arrayOfBits[i])
		{
			return size - i + 1;;
		}
	}
}


void bitwise::Number::printBinary()
{
	// Check if arrayOfBits is not null
	if (!(this->arrayOfBits))
	{
		cout << endl;
		cerr << "Can not print decimal value.\n\tBinary value was not set properly.\n" << endl;
		throw "ERROR: arrayOfBits points to nullptr\n";
	}
	
	for (int i = size - getActualLength(); i < size; ++i)
	{
		cout << this->arrayOfBits[i];
	}
	
	cout << endl;
}


pair<int, int> bitwise::handleUserInput()
{
	
	setlocale(LC_ALL, "Russian");
	
	cout << "\nВведите 2 числа (в десятичное системе счисления):" << endl;
	
	cout << "\tПервое число: ";
	int first = 0;
	cin >> first;
	cout << endl;
	
	cout << "\tВторое число: ";
	int second = 0;
	cin >> second;
	cout << endl;
	
	return make_pair(first, second);
}


void bitwise::sumBinaryNumbers(bitwise::Number *first, bitwise::Number *second, bitwise::Number *sum)
{
	const bool *secondBinary = second->arrayOfBits;
	const bool *firstBinary = first->arrayOfBits;
	bool *result = new bool[size];
	
	bool shift = false;
	for (int i = size - 1; i >= 0; --i)
	{
		switch (firstBinary[i] + secondBinary[i] + shift)
		{
			case 3:
			{
				shift = true;
				result[i] = true;
				break;
			}
			
			case 2:
			{
				shift = true;
				result[i] = false;
				break;
			}
			
			case 1:
			{
				shift = false;
				result[i] = true;
				break;
			}
			
			default:
			{
				shift = false;
				result[i] = false;
				break;
			}
		}
	}
	
	sum->arrayOfBits = result;
}


int bitwise::performOperations(bool testingMode, int firstValue, int secondValue)
{
	Number *first = nullptr;
	Number *second = nullptr;
	auto *sum = new Number();
	
	if (testingMode)
	{
		first = new Number(firstValue);
		second = new Number(secondValue);
	}
	else
	{
		// Get numbers from keyboard (console)
		pair<int, int> valuePair = handleUserInput();
		
		first = new Number(valuePair.first);
		second = new Number(valuePair.second);
	}
	
	cout << "\nПервое число: " << first->decimalValue << endl;
	cout << "Двойчное представление:" << endl;
	first->generateBinary();
	first->printBinary();
	
	cout << "\nВторое число: " << second->decimalValue << endl;
	cout << "Двойчное представление:" << endl;
	second->generateBinary();
	second->printBinary();
	
	cout << "\nСложим эти числа в столбик:" << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	
	first->printBinary();
	cout << "+" << endl;
	second->printBinary();
	
	sumBinaryNumbers(first, second, sum);
	cout << "___________________________" << endl;
	sum->printBinary();
	sum->generateDecimal();
	
	int result = sum->decimalValue;
	cout << "\n=> Результат в десятичной системе счисления: " << result << endl;
	
	delete first;
	delete second;
	delete sum;
	
	return result;
}


// 88          88                                   88
// 88          ""                                   88
// 88                                               88
// 88,dPPYba,  88  ,adPPYba, 8b       d8  ,adPPYba, 88  ,adPPYba,
// 88P'    "8a 88 a8"     "" `8b     d8' a8"     "" 88 a8P_____88
// 88       d8 88 8b          `8b   d8'  8b         88 8PP"""""""
// 88b,   ,a8" 88 "8a,   ,aa   `8b,d8'   "8a,   ,aa 88 "8b,   ,aa
// 8Y"Ybbd8"'  88  `"Ybbd8"'     Y88'     `"Ybbd8"' 88  `"Ybbd8"'
//                              d8'