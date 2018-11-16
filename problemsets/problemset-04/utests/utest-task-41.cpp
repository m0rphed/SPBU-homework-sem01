#include "../tasks/task-41-twos-complement.h"

#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>

#include <iostream>

using namespace std;
using namespace magicNumber;


TEST(problemset04, twosComplementTest)
{
	int inputValue = 0;
	
	// Allow Russian in I/O.
	setlocale(LC_ALL, "Russian");
	
	getInput(inputValue, true, 12);
	auto *first = new Number(inputValue, getBitMask(inputValue));
	cout << "\n " << first->value << " в двоичном представлениии:" << endl;
	printBinary(first);
	
	getInput(inputValue, true, 129);
	auto *second = new Number(inputValue, getBitMask(inputValue));
	cout << "\n " << second->value << " в двоичном представлениии:" << endl;
	printBinary(second);
	
	auto *Sum = new Number(first->value + second->value, getBitMask(inputValue));
	cout << "\n Сумма в двоичном представлениии:" << endl;
	printBinary(Sum);
	cout << "\n Сумма в десятичном представлениии:" << endl;
	cout << Sum->value << endl;
	
	delete first;
	delete second;
	delete Sum;
}
