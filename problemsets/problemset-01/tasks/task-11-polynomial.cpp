#include "task-11-polynomial.h"
#include <stdio.h>


float polynomial(float x)
{
	printf("Value of x: %f\n", x);
	
	float squareX = x * x;
	float result = (squareX + x) * (squareX + 1) + 1;
	
	printf("\nx^4 + x^3 + x^2 + x + 1 = %f\n", result);
	return result;
}
