#include "task-11-polynomial.h"
#include <stdio.h>


float polynomial(float x)
{
	printf("\nValue of x: %f", x);
	
	float squareX = x * x;
	float result = (squareX + x) * (squareX + 1) + 1;
	
	printf("\n\tx^4 + x^3 + x^2 + x + 1 = %f\n", result);
	return result;
}
