#include "task-23-counting-bubbles.h"
#include "arrayHelpers.h" // findMinMax()


// Classic implementation of bubble sort algorithm
// expected time complexity: O(n^2)
void bubbleSort(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = size - 1; j > i; --j)
		{
			if (array[j - 1] > array[j])
			{
				int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
		
	}
}


// Implementation of counting sort algorithm
// expected time complexity: O(n)
void countingSort(int *array, int size)
{
	// So in the most general case maximum key value (k) will be known in advance,
	// and can be assumed to be part of the input to the algorithm.
	// (so usually we don't need variables 'min' and 'max')
	
	// If the value of k (maximum key value) is not already known then it may be computed and saved in a variable.
	int min = array[0];
	int max = array[0];
	
	// function findMinMax() computes maximum key value and minimum key value,
	// by an additional loop over the array.
	findMinMax(array, size, min, max);
	
	auto *tempArray = new int[max - min + 1]{};
	
	for (int i = 0; i < size; ++i)
	{
		++tempArray[array[i] - min];
	}
	
	int currentIndex = 0;
	for (int i = 0; i < max - min + 1; ++i)
	{
		while (tempArray[i] > 0)
		{
			--tempArray[i];
			array[currentIndex] = i + min;
			++currentIndex;
		}
	}
	
	delete[] tempArray;
}
