#include "testwork-2-4-matrix-sort.h"

#include <gtest/gtest.h> // Google Test Framework
#include <vector>
#include <iostream>

typedef int ElementType;
using namespace std;

TEST(task1_matrix_sort, printMyMatrixTest)
{
	vector<vector<ElementType>> myMatrix = {};
	
	const int n = 5;
	const int m = 5;
	
	unsigned int counter = 0;
	
	for (int i = 0; i < n; ++i)
	{
		vector<ElementType> temp = {};
		for(int j = 0; j < m; ++j)
		{
			temp.push_back(counter);
			++counter;
		}
		myMatrix.push_back(temp);
	}
	
	printMatrix(myMatrix, n, m);
	
	SUCCEED();
}


TEST(task1_matrix_sort, sortMyMatrixTest)
{
	vector<vector<ElementType>> myMatrix = {};
	
	const int n = 5;
	const int m = 5;
	
	unsigned int counter = n*m;
	
	for (int i = 0; i < n; ++i)
	{
		vector<ElementType> temp = {};
		for(int j = 0; j < m; ++j)
		{
			temp.push_back(counter);
			--counter;
		}
		myMatrix.push_back(temp);
	}
	
	printMatrix(myMatrix, n, m);
	
	sortMatrixColumns(myMatrix);
	
	printMatrix(myMatrix, n, m);
	
	SUCCEED();
}