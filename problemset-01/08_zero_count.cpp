#include <stdio.h>

int main()
{
	int n = 0, counter = 0;

	printf("Enter length of an array:\n");
	scanf("%d", &n);

	auto *arr = new float[n];

	for (int i = 0; i < n; ++i)
	{
		scanf("%f", &arr[i]);

		if (arr[i] == 0)
		{
			counter++;
		}
	}

	printf("Number of zero elements: %d", counter);

	delete[] arr;
	return 0;
}
