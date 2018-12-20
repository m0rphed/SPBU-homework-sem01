#include "testwork-2-4-matrix-sort.h"

#include <gtest/gtest.h> // Google Test Framework
#include <vector>
#include <iostream>

typedef int ElementType;
using namespace std;

TEST(easyestTestWork, task1_matrix_sort)
{
	vector<int> v;
	int size;
	cin >> size;
	int a;
	for (int i = 0; i < size; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	FAIL();
}