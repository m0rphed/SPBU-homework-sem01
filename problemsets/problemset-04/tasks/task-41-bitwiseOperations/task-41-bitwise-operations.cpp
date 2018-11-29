#include "task-41-bitwise-operations.h"

#include <cmath>
#include <utility>
#include <iostream>
#include <locale>

using namespace std;


int findMax(const int first, const int second)
{
	return (first > second) ? first : second;
}


int findDifference(const int first, const int second)
{
	return abs(second - first);
}


bitwise::Number::Number(const int &value)
{
	this->decimalValue = value;
	this->arrayLength = checkLength();
	this->generateBinary();
}


bitwise::Number::~Number()
{
	delete bitArray;
}


int bitwise::Number::getDecimal()
{
	return this->decimalValue;
}


bool *bitwise::Number::getBinary()
{
	return this->bitArray;
}


int bitwise::Number::checkLength()
{
	return (int) (ceil(log(this->decimalValue) / log(2)) + 2);
}


void bitwise::Number::setDecimal(const int &value)
{
	this->decimalValue = value;
}


void bitwise::Number::setBinary(bool *pointerToArray)
{
	delete this->bitArray;
	this->bitArray = pointerToArray;
}


void bitwise::Number::generateDecimal()
{
	const int length = this->arrayLength;
	double decimal = 0;
	
	int sign = (this->bitArray[0]) ? -1 : 1;
	
	int power = 0;
	for (int i = length - 1; i >= 0; --i)
	{
		if (this->bitArray[i])
		{
			decimal += pow(2, power);
		}
		++power;
	}
	
	this->decimalValue = (int) (sign * decimal);
}


void bitwise::Number::generateBinary()
{
	const int length = this->arrayLength;
	auto arrayOfBits = new bool[length];
	
	int decimal = this->decimalValue;
	arrayOfBits[0] = (decimal < 0);
	
	for (int i = length - 1; i >= 0; --i)
	{
		arrayOfBits[i] = decimal % 2 != 0;
		decimal /= 2;
	}
	
	this->bitArray = arrayOfBits;
}


void bitwise::Number::printBinary()
{
	const int length = this->arrayLength;
	
	for (int i = 0; i < length; ++i)
	{
		cout << bitArray[i];
	}
	
	cout << endl;
}


void bitwise::Number::shiftBits(const int &n)
{
	const int length = this->arrayLength;
	
	const bool *array = this->bitArray;
	bool *shifted = new bool[length + n];
	
	for (int i = 0; i <= n; ++i)
	{
		shifted[i] = false;
	}
	
	for (int i = n + 1; i < length + n; ++i)
	{
		shifted[i] = array[i - n];
	}
	
	delete this->bitArray;
	this->arrayLength = length + n;
	this->bitArray = shifted;
}


void bitwise::Number::setLength(const int &value)
{
	this->arrayLength = value;
}


void bitwise::updateBitArray(Number *first, Number *second)
{
	const int max = findMax(first->checkLength(), second->checkLength());
	const int difference = findDifference(first->checkLength(), second->checkLength());
	
	if (first->checkLength() < max)
	{
		first->shiftBits(difference);
	}
	else
	{
		second->shiftBits(difference);
	}
}


void bitwise::sumTwoBinaryNumbers(Number *first, Number *second, Number *sum)
{
	updateBitArray(first, second);
	const int length = first->checkLength();
	
	const bool *secondBinary = second->getBinary();
	const bool *firstBinary = first->getBinary();
	bool *result = new bool[length];

	bool shift = false;
	for (int i = length - 1; i >= 0; --i)
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
	
	sum->setLength(length);
	sum->setBinary(result);
}


pair<int, int> bitwise::handleUserInput()
{
	setlocale(LC_ALL, "Russian");
	
	int first = 0;
	int second = 0;
	
	cout << "\nВведите 2 числа (в десятичное системе счисления):" << endl;
	
	cout << "\tПервое число: ";
	cin >> first;
	cout << endl;
	
	cout << "\tВторое число: ";
	cin >> second;
	cout << endl;
	
	return make_pair(first, second);
}


void bitwise::performOperations(const bool testingMode, const int firstValue, const int secondValue)
{
	setlocale(LC_ALL, "Russian");
	
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
		pair<int, int> valuePair = handleUserInput();
		
		first = new Number(valuePair.first);
		second = new Number(valuePair.second);
	}
	
	cout << "\nПервое число: " << first->getDecimal() << endl;
	cout << "Двойчное представление:" << endl;
	first->printBinary();
	
	cout << "\nВторое число: " << second->getDecimal() << endl;
	cout << "Двойчное представление:" << endl;
	second->printBinary();
	
	cout << "\nСложим эти числа в столбик:" << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	
	first->printBinary();
	cout << "+" << endl;
	second->printBinary();
	
	sumTwoBinaryNumbers(first, second, sum);
	cout << "___________________________" << endl;
	sum->printBinary();
	sum->generateDecimal();
	
	cout << "\n  Результат в десятичной системе счисления: " << sum->getDecimal() << endl;
	
	delete first;
	delete second;
	delete sum;
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
//                             d8'