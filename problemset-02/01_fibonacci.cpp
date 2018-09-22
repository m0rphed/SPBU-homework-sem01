#include <math.h> // floor(), pow(), sqrt()


// using recursion
long long recursiveFib(long long fibLast, long long fibNow, int n)
{
	if (--n > 0)
	{
		return recursiveFib(fibNow, fibLast + fibNow, n);
	}
	return fibNow;
}


// using loop
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


// using "Binet's Fibonacci Number Formula"
unsigned long long analyticFib(unsigned n)
{
	// Yeah... that formula:
	return floor((pow((1 + sqrt(5)) / 2, n) - pow(1 - ((1 + sqrt(5)) / 2), n)) / sqrt(5));
}