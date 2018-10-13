#include "task_04_sort_rand_array.h"
#include "arrayHelpers.h"

void strangeSort(int *array, const int size)
{
	int pos = 1;
	for (int i = 1; i < size; ++i)
	{
		// If current element smaller than first,
		// then swap these elements!
		if (array[i] < array[0])
		{
			int tmp = array[pos];
			array[pos] = array[i];
			array[i] = tmp;
			
			pos++;
		}
	}
}