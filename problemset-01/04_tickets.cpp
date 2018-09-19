#include <stdio.h>

int main()
{

	unsigned int counter = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				for (int l = 0; l < 10; l++)
				{
					for (int m = 0; m < 10; m++)
					{
						for (int n = 0; n < 10; n++)
						{
							if (i + j + k == l + m + n)
								counter++;
						}
					}
				}
			}
		}
	}

	printf("Number of lucky tickets: %u", counter);
	return 0;
}
