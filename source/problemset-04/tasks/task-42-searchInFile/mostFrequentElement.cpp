#include "mostFrequentElement.h"

// implementation of Quick Sort Algorithm
#include "quickSortAlgorithm.h"


int findMostFrequent(int *array, const int size)
{
	// At first, we need to quickSort() the array.
	// Time complexity: O(n*log(size))
	quickSort(array, 0, size - 1);
	
	int counter = 0;
	int maxFrequency = 0;
	int mostFrequent = array[0];
	
	for (int i = 1; i < size; ++i)
	{
		if (array[i] == array[i - 1])
		{
			++counter;
		}
		else
		{
			counter = 1;
		}
		
		if (counter > maxFrequency)
		{
			maxFrequency = counter;
			mostFrequent = array[i - 1];
		}
	}
	
	return mostFrequent;
}
