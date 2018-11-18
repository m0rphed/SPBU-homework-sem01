#pragma once
// Include task-4.1
#include "../tasks/task-41-bitwiseOperations/task-41-bitwise-operations.h"
#include <gtest/gtest.h>


// Abstract Test Class
class NumberFixture : public ::testing::Test
{
public:
	
	// Func. defines values and masks
	// for firstNumber, secondNumber, Sum
	void setNumberPair(int firstValue, int secondValue);
	
	// Prints decimal and binary representation
	// of firstNumber and secondNumber
	void printNumbersInfo();
	
	// Prints decimal and binary representation of
	// the Sum(firstNumber, secondNumber)
	void printNumbersSum();

protected:
	
	// This is standard fixture constructor
	// Google Test Fixtures manual:
	//   https://github.com/google/googletest/blob/master/googletest/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests
	virtual void SetUp()
	{
		firstNumber = new bitwise::Number(0, 0);
		secondNumber = new bitwise::Number(0, 0);
		Sum = new bitwise::Number(0, 0);
	}
	
	virtual void TearDown()
	{
		delete firstNumber;
		delete secondNumber;
		delete Sum;
	}
	
	bitwise::Number *firstNumber = nullptr;
	bitwise::Number *secondNumber = nullptr;
	bitwise::Number *Sum = nullptr;
};
