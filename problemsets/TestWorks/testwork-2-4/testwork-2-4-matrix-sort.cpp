#include "testwork-2-4-matrix-sort.h"
#include <vector>
#include <iostream>

typedef int ElementType;
using namespace std;

vector<ElementType> getFirstRow(vector<vector<ElementType>> &myMatrix)
{
	const unsigned long numberOfColumns = myMatrix[0].size();
	
	vector<int> firstRow;
	for (int j = 0; j < numberOfColumns; ++j)
	{
		firstRow.push_back(myMatrix[0][j]);
	}
	
	return firstRow;
}


void swapColumns(vector<vector<ElementType>> &myMatrix, const int &firstColumn, const int &secondColumn)
{
	const unsigned long numberOfRows = myMatrix.size();
	const unsigned long numberOfColumns = myMatrix[0].size();
	
	for (auto &row : myMatrix)
	{
		swap(row[firstColumn], row[secondColumn]);
	}
}


void sortMatrixColumns(vector<vector<ElementType>> &myMatrix)
{
	const unsigned long numberOfRows = myMatrix.size();
	const unsigned long numberOfColumns = myMatrix[0].size();
	
	vector<int> order = getFirstRow(myMatrix);
	
	for (int j = 0; j < numberOfColumns - 1; ++j)
	{
		for (int t = 0; t < numberOfColumns - j - 1; ++t)
		{
			if (order[t] > order[t + 1])
			{
				// меняем элементы местами
				swapColumns(myMatrix, t, t + 1);
			}
		}
	}
}


void printMatrix(vector<vector<ElementType>> &myMatrix, const int &numberOfRows, const int &numberOfColumns)
{
	cout << endl;
	for (int i = 0; i < numberOfRows; ++i)
	{
		for (int j = 0; j < numberOfColumns; ++j)
		{
			cout << myMatrix[i][j] << "  ";
		}
		
		cout << endl;
	}
}
