#include <stdlib.h> // qsort()
#include <time.h>   // time()
#include <math.h>   // pow()

#include "../../problemsets/problemset-02/arrayHelpers.h"
#include "task-32-quick-binary-search.h"


int binarySearch(int *array, int length, int item)
{
	int low = 0;
	int high = length;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int guess = array[mid];
		
		if (guess == item)
		{
			return mid;
		}
		else if (guess > item)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1; // number not found
}


// | qBinarySearch function:
// | do quickSort() for an array (which size = n):                      => O(n*log(n))
// | do binarySearch() for arrayOfNums (which contains k numbers):      => O(k*log(n))
// | expected time complexity:                                          => O(n*log(n) + k*log(n))

void qBinarySearch(int *array, const int n, int *arrayOfNums, const int k, int *foundMatches)
{
	qsort(array, n, sizeof(int), isIncreasing); //expected time complexity: O(n*log(n))
	
	for (int i = 0; i < k; ++i) //expected time complexity: O(k*log(n))
	{
		if (binarySearch(array, n, arrayOfNums[i]) != -1) // O(log(n))
		{
			foundMatches[i] = arrayOfNums[i];
		}
	}
}
