#include "task-22-power.h"


// expected complexity of the algorithm: O(n)
long long simplePow(long long value, int exponent)
{
	// any number raised to the matrixPower of zero equal 1
	if (!exponent)
	{
		return 1;
	}
	
	long long result = 1;
	
	exponent -= 1;
	
	while (exponent > 0 && value)
	{
		result *= value;
		--exponent;
	}
	
	return result * value;
}


// expected time complexity of the algorithm: О(log(n))
long long binaryPow(long long value, int exponent)
{
	long long result = 1;
	while (exponent)
	{
		if (exponent & 1)
		{
			result *= value;
		}

		value *= value;
		exponent >>= 1;
	}
	return result;
}
