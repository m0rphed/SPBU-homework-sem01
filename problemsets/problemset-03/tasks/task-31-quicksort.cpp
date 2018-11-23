#include "task-31-quicksort.h"

#include <stdlib.h>
#include <math.h> // abs()


// Attention! Parameters 'start', 'end' -- indices of an array
void insertionSort(int *array, int start, int end)
{
	for (int i = start + 1; i <= end; ++i)
	{
		int current = array[i];
		int j = i;
		
		while (j > 0 && array[j - 1] > current)
		{
			array[j] = array[j - 1];
			--j;
		}
		
		array[j] = current;
	}
}


// Partition by pivot
// function is a part of quickSort implementation
int partition(int *array, const int start, const int end)
{
	int pivot = array[end];
	
	int i = start - 1;
	int temp = 0;
	
	for (int j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	
	return i + 1;
}


// Quick Sort
// Attention! Parameters 'start', 'end' -- indices of an array
void quickSort(int *array, int start, int end)
{
	int const size = abs(start + end + 1);
	
	if (size < 10)
	{
		insertionSort(array, start, end);
	}
	else
	{
		if (start < end)
		{
			const int pivot = partition(array, start, end);
			quickSort(array, start, pivot - 1);
			quickSort(array, pivot + 1, end);
		}
	}
}
