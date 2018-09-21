#include <stdio.h>

// handles input
void getInput(int *arr, int len)
{
	printf("Enter an array:\n");
	for (int i = 0; i < len; ++i)
	{
		scanf("%d", &arr[i]);
	}
}

// function reverses the array from position 'beg' to position 'end' inclusive
void reverseArrPart(int *arr, int beg, int end)
{
	// fix arr indices
	beg--;
	end--;

	// middle index of array range
	int middle = ((beg + end) / 2) + 1;

	for (int i = beg, tmp = 0; i < middle; i++)
	{
		tmp = arr[i];
		arr[i] = arr[beg + end - i];
		arr[beg + end - i] = tmp;
	}
}

int main()
{
	int m = 0;
	int n = 0;

	printf("Enter value of m and n:\n");

	printf("m = ");
	scanf("%d", &m);

	printf("n = ");
	scanf("%d", &n);

	if (m <= 0 || n <= 0)
	{
		printf("Error: m, n must satisfy condition:\n\t m, n > 0.");
		return 0;
	}

	auto *array = new int[m + n];

	getInput(array, n + m);

	// flip first part of the array[1 : m]
	reverseArrPart(array, 1, m);

	// flip second part of the array[m+1 : m+n]
	reverseArrPart(array, m + 1, m + n);

	// flip the whole array
	reverseArrPart(array, 1, m + n);

	printf("Result:\n");

	for (int i = 0; i < m + n; ++i)
	{
		printf("%d ", array[i]);
	}

	delete[] array;
	return 0;
}
