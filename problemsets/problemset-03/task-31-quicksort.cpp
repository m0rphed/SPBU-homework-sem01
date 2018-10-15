#include <stdlib.h>
#include <math.h>
#include "task-31-quicksort.h"


void insertionSort(int *array, int size)
{
	for (int i = 1; i < size; ++i)
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
int partition(int *array, int start, int end)
{
	int pivot_id = rand() % (end - start) + 1;
	int pivot = array[pivot_id];
	
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
void quickSort(int *array, int start, int end)
{
	if (abs(start + end) < 10)
	{
		insertionSort(array, abs(start + end));
	}

	if (start < end)
	{
		int q = partition(array, start, end);
		
		quickSort(array, start, q - 1);
		quickSort(array, q + 1, end);
	}
}
