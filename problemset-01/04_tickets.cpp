#include <stdio.h>

int main()
{

	int array[28]{};
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
