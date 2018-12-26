#include "../../HelperFunctions/arrayHelpers.h"
#include "task-32-quick-binary-search.h"

#include <stdlib.h> // qsort()
#include <time.h>   // time()
#include <math.h>   // pow()


int binarySearch(int *array, const int length, int item)
{
	// non-const variables
	int low = 0;
	int high = length;
	
	while (low <= high)
	{
		const int mid = (low + high) / 2;
		const int guess = array[mid];
		
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

void qBinarySearch(int *array, const int n, int *arrayOfNums, const int k, bool *foundMatches)
{
	qsort(array, n, sizeof(int), compareIncreasing); //expected time complexity: O(n*log(n))
	
	for (int i = 0; i < k; ++i) //expected time complexity: O(k*log(n))
	{
		if (binarySearch(array, n, arrayOfNums[i]) != -1) // O(log(n))
		{
			foundMatches[i] = true;
		}
	}
}
