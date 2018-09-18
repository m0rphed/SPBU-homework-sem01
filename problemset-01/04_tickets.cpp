#include <stdio.h>

// returns count of lucky tickets
unsigned int count_lucky(const int sum)
{

	unsigned int counter = 0;

	// i, j, k — first three digits of a six-digit ticket
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (i + j + k == sum)
					counter++;
			}
		}
	}

	// number of lucky tickets = counter^2 for six-digit tickets
	return counter * counter;
}

int main()
{
	int sum = 0;

	printf("Enter the sum:\n");
	scanf("%d", &sum);

	printf("%d", count_lucky(sum));

	return 0;
}
