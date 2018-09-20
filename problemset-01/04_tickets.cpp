#include <stdio.h>

// Length of the array = 28 = (27 + 1)
// because this is the number of all possible sums
// in the first 3 digits of the ticket.
const int arrSize = 28;

int main()
{
	int array[arrSize]{};
	int sum = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				++array[i + j + k];
			}
		}
	}
	for (auto elem : array)
	{
		sum += elem * elem;
	}

	printf("Number of lucky tickets: %d", sum);
	return 0;
}
