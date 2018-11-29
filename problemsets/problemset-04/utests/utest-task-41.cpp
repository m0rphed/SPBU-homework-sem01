#include "../tasks/task-41-bitwiseOperations/task-41-bitwise-operations.h"

#include <gtest/gtest.h> // Google Test Framework
#include <locale> // setlocale()


TEST(problemset04, shitTest)
{
	setlocale(LC_ALL, "Russian");
	bitwise::performOperations(true, 32, 16);
	SUCCEED();
}
