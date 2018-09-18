#include <stdio.h>

int main()
{
	float x = .0;

	printf("Enter value x:\n");
	scanf("%f", &x);

	printf("x^4 + x^3 + x^2 + x + 1 = %f\n", (x * x + x) * (x * x + 1) + 1);
	return 0;
}
