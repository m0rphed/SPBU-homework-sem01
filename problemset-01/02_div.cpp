#include <stdio.h>

int main()
{
	unsigned long long a = 0, b = 0;
	unsigned int counter = 0;

	printf("Enter the dividend:\n  a = ");
	scanf("%d", &a);

	printf("Enter the divisor:\n  b = ");
	scanf("%d", &b);

	while (a >= b)
	{
		a -= b;
		counter++;
	}

	printf("The result of integer division:\n  %d", counter);
}
