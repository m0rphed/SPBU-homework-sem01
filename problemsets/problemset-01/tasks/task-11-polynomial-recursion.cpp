#include <stdio.h>

// For any polynomial of this kind, we can calculate its value recursively:
// x^4 + x^3 + x^2 + x + 1 = x*(x*(x*(x + 1) + 1) + 1) + 1
// it is enough to know the power and the value of x

float recursive_way(float x, int k, int power)
{
	if (k < power)
	{
		x *= recursive_way(x, k + 1, power);
	}
	return x + 1;
}

int main()
{
	float x;

	printf("Enter value x:\n");
	scanf("%f", &x);

	printf("x^4 + x^3 + x^2 + x + 1 = %f\n", (x * x + x) * (x * x + 1) + 1);
	printf("%f\n", recursive_way(x, 1, 4));

	return 0;
}
