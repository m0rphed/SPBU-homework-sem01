#include "../tasks/task-41-bitwiseOperations/task-41-bitwise-operations.h"
#include "../testFixtures/NumberFixture.h"

#include <gtest/gtest.h> // Google Test Framework
#include <gmock/gmock.h>
#include <locale> // setlocale()


TEST_F(NumberFixture, zeroTest)
{
	setlocale(LC_ALL, "Russian");
	
	EXPECT_EQ(0, firstNumber->value);
	EXPECT_EQ(0, secondNumber->value);
	
	setNumberPair(32, 16);
	
	EXPECT_EQ(32, firstNumber->value);
	EXPECT_EQ(16, secondNumber->value);
	EXPECT_EQ(48, Sum->value);
	EXPECT_EQ(128, Sum->mask);
	
	printNumbersInfo();
	printNumbersSum();
}
