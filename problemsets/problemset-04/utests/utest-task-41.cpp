#include "../tasks/task-41-bitwiseOperations/bitwiseOperations.h"

#include <gtest/gtest.h> // Google Test Framework
#include <locale> // setlocale()


TEST(problemset04, shitTest)
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	
	cout << "\nТЕСТ-1:" << endl;
	ASSERT_EQ(48, bitwise::performOperations(true, 32, 16));
	cout << endl;
	
	cout << "\nТЕСТ-2:" << endl;
	ASSERT_EQ(123, bitwise::performOperations(true, 111, 12));
	cout << endl;
	
	cout << "\nТЕСТ-3:" << endl;
	ASSERT_EQ(100, bitwise::performOperations(true, 111, -11));
	cout << endl;
	
	cout << "\nТЕСТ-4:" << endl;
	ASSERT_EQ(-169, bitwise::performOperations(true, -157, -12));
	cout << endl;
}
