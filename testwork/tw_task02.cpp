#include <stdio.h>
void printArray(int array[10])
{
	printf("\nStart of an array.");
	for (auto x : array[])
	{
		printf(x);
	}
	printf("\nEnd of an array.");
}

void selectionSort(int *array, int size)
{
	int indexOfMin = 0;

	for (int i = 0; i < size - 1; i++)
	{
		indexOfMin = i;
		for (int j = i + 1; j < size; j++)
		{
			if (array[j] < array[indexOfMin])
			{
				indexOfMin = j;
			}
		}
		
		int tmp = array[indexOfMin];
		array[indexOfMin] = array[i];
		array[i] = tmp;
	}
}

int main()
{
	const unsigned int size = 10;
	int testArray[size] = {99, 8, 1221, 54, 0, 31, 1, 22, 44, 12};
	
	printf("TestArray is {99, 8, 1221, 54, 0, 31, 1, 22, 44, 12}\n");
	selectionSort(testArray, size);
	printArray(testArray);
}