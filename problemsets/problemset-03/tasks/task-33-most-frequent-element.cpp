#include "task-33-most-frequent-element.h"
#include "../tasks/task-31-quicksort.h"

#include <exception>
#include <iostream>

using namespace std;


// Function sillySolution::findMostFrequent - returns the most frequent element in given array
int sillySolution::findMostFrequent(int *array, int *frequencyValues, const int size)
{
	int maxFrequency = 0;
	int mostFrequent = 0;
	
	for (int i = 0; i < size; ++i)
	{
		// increment frequency value for element array[i]
		++frequencyValues[array[i]];
		
		if (frequencyValues[array[i]] > maxFrequency)
		{
			maxFrequency = frequencyValues[array[i]];
			mostFrequent = array[i];
		}
	}
	
	// Special case:
	//   What if there are several elements
	//   in the array with maximum frequency?
	
	// So, IF we need to find other elements with max frequency
	//   => we can iterate through frequencyValues[], which is assessable outer scope.
	return mostFrequent;
}


int smartSolution::findMostFrequent(int *array, const int size)
{
	try
	{
		// At first, we need to quickSort() the array.
		// Expected time complexity: O(n*log(size))
		quickSort(array, 0, size - 1);
	}
	catch (exception &error)
	{
		cerr << "ERROR: Error sorting an array" << endl;
		cerr << error.what() << endl;
		throw "\tFunction quickSort() -- failed!";
	}
	
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
