#pragma once

#include <vector>

typedef int ElementType;
using namespace std;

vector<ElementType> getFirstRow(vector<vector<ElementType>> &myMatrix);

void swapColumns(vector<vector<ElementType>> &myMatrix, const int &firstColumn, const int &secondColumn);

// Sort matrix columns by first element
void sortMatrixColumns(vector<vector<ElementType>> &myMatrix);

void printMatrix(vector<vector<ElementType>> &myMatrix, const int &numberOfRows, const int &numberOfColumns);