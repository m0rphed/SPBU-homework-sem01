#include <stdio.h>   // puts()
#include <stdlib.h>  // srand(), rand()
#include "arrayHelpers.h"


void fillArray(int myArray[], int size, int min, int max, bool isRandom)
{
	if (isRandom)
	{
		randomizeArray(myArray, size, min, max);
	}
		// If the array will not be filled with random values,
		// it will be filled with consecutive values from 'min' to 'max'
	else
	{
		if (max < min)
		{
			printf("Error occurred in func. fillArray()\n\tsource: arrayHelpers.cpp\n");
			printf("ERROR: max = %d < min = %d\n", max, min);
		}
		
		myArray[0] = min;
		for (int i = 1; i < size; ++i)
		{
			// Reset value if it's greater than (or equal to) 'max'
			if (myArray[i - 1] >= max)
			{
				myArray[i] = min;
			}
			else
			{
				myArray[i] = myArray[i - 1] + 1;
			}
		}
	}
}


void copyArray(int arrayCopy[], int originalArray[], int size) // 'size' is the same for both arrays.
{
	for (int i = 0; i < size; ++i)
	{
		arrayCopy[i] = originalArray[i];
	}
}


void randomizeArray(int myArray[], int size, int min, int max)
{
	for (int i = 0; i < size; ++i)
	{
		// generate pseudo random number between min and max:
		myArray[i] = rand() % (max - min + 1) + min;
	}
}


int compareIncreasing(const void *first, const void *second)
{
	return (*(const int *) first > *(const int *) second) - (*(const int *) first < *(const int *) second);
}


void findMinMax(int const *array, int size, int &min, int &max)
{
	for (int i = 0; i < size; ++i)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		if (array[i] > max)
		{
			max = array[i];
		}
	}
}


void printArray(int const *array, int size)
{
	printf("\t\t[ ");
	for (int i = 0; i < size; ++i)
	{
		printf(" %d,", array[i]);
	}
	printf(" ]\n");
}