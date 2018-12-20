#include "testwork-2-4-matrix-sort.h"
#include <vector>
#include <iostream>

typedef int ElementType;
using namespace std;

void printMatrix(ElementType &&myMatrix, const int &numberOfRows, const int &numberOfColumns)
{
	for (int i = 0; i < numberOfRows; ++i)
	{
		for (int j = 0; j < numberOfColumns; ++j)
		{
			cout <<
		}
	}
}

vector<ElementType> getFirstRow(vector<vector<ElementType>> &myMatrix)
{
	const unsigned long numberOfColumns = myMatrix[0].size();
	
	vector<int> firstRow;
	for (int j = 0; j < numberOfColumns; ++j)
	{
		firstRow.push_back(myMatrix[1][j]);
	}
}

void swapColumns(vector<vector<ElementType>> &myMatrix, const int &i, const int &j)
{

}


// Sort matrix columns by first element
void sortMatrixColumns(vector<vector<ElementType>> &myMatrix)
{
	const unsigned long numberOfRows = myMatrix.size();
	const unsigned long numberOfColumns = myMatrix[0].size();
	
	vector<int> order = getFirstRow(myMatrix);
	
	for (int j = 0; j < numberOfColumns - 1; ++j)
	{
		if (&order[j] > &order[j+1])
		{
		
		}
	}
	
	for ()
	{
	}
	for (auto & : myMatrix)
	{
	
	}
	std::swap(v[2], v[3]);
	for (int i = 0; i < numberOfRows; i++)
	{
		cout << v[i] << " ";
	}
	return 0;
	
}


void createVector(vector<vector<ElementType>> &myMatrix)
{

}