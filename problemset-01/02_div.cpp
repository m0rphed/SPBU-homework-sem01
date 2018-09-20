#include <stdio.h>
#include <math.h>

int main()
{
	long long a = 0, b = 0;
	int sign = 1;
	int counter = 0;

	printf("Enter the dividend:\n  a = ");
	scanf("%lld", &a);

	printf("Enter the divisor:\n  b = ");
	scanf("%lld", &b);

	if (b == 0)
	{
		printf("Error: devision by 0\n");
		return 0;
	}

	if (a < 0 ^ b < 0)
	{
		sign *= -1;
	}

	a = abs(a);
	b = abs(b);

	while (a >= b)
	{
		a -= b;
		counter++;
	}

	printf("The result of integer division:\n  %d", sign * counter);
	return 0;
}
