#include "quickSortAlgorithm.h"


// Partition by pivot
int arrayPartition(int *array, int start, int end)
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
	if (start < end)
	{
		int q = arrayPartition(array, start, end);
		quickSort(array, start, q - 1);
		quickSort(array, q + 1, end);
	}
}
