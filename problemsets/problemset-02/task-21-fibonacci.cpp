#include "task-21-fibonacci.h"
#include <math.h> // floor(), pow(), sqrt()


// Task: implement the calculation of Fibonacci numbers.
// Here are a few different implementations:


long long recursiveFib(long long n)
{
	if (n <= 1)
	{
		return n;
	}
	return recursiveFib(n - 1) + recursiveFib(n - 2);
}


long long iterativeFib(int n)
{
	long long last = 0;
	long long next = 1;
	long long tmp = 0;
	
	while (--n > 0)
	{
		tmp = last + next;
		last = next;
		next = tmp;
	}
	return next;
}


long long analyticFib(unsigned n)
{
	// Binet's Formula
	return floor((pow((1 + sqrt(5)) / 2, n) - pow(1 - ((1 + sqrt(5)) / 2), n)) / sqrt(5));
}


int matrixFib(int n)
{
	int F[2][2] = {{1, 1},
	               {1, 0}};
	if (n == 0)
	{
		return 0;
	}
	
	matrixPower(F, n - 1);
	return F[0][0];
}


void matrixMultiply(int firstMatrix[2][2], int secondMatrix[2][2])
{
	// x, y, z, w -- are temporary variables
	// used as storage for different values of the matrix
	int x = firstMatrix[0][0] * secondMatrix[0][0] + firstMatrix[0][1] * secondMatrix[1][0];
	int y = firstMatrix[0][0] * secondMatrix[0][1] + firstMatrix[0][1] * secondMatrix[1][1];
	int z = firstMatrix[1][0] * secondMatrix[0][0] + firstMatrix[1][1] * secondMatrix[1][0];
	int w = firstMatrix[1][0] * secondMatrix[0][1] + firstMatrix[1][1] * secondMatrix[1][1];
	
	firstMatrix[0][0] = x;
	firstMatrix[0][1] = y;
	firstMatrix[1][0] = z;
	firstMatrix[1][1] = w;
}


void matrixPower(int first[2][2], int n)
{
	if (n == 0 || n == 1)
	{
		return; // if power = 0 || 1
				// then exit.
	}
	int second[2][2] = {{1, 1},
	                    {1, 0}};
	
	matrixPower(first, n / 2);
	matrixMultiply(first, first);
	
	if (n % 2 != 0)
	{
		matrixMultiply(first, second);
	}
}
