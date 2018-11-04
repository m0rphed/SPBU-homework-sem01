#include <stdio.h>

int main()
{
	int limit = 0, number = 0;

	printf("Enter the limit of primes numbers search:\n");
	scanf("%d", &limit);

	// create an array with indices from 0 to limit + 1
	auto *primes = new bool[limit + 1];

	// '0' and '1' are not primes
	// so the first two elements will be initialized as "false"
	primes[0] = primes[1] = false;

	// the rest of the array will be initialized as "true"
	for (int i = 2; i <= limit; ++i)
	{
		primes[i] = true;
	}

	// implementation of the "sieve of Eratosthenes" algorithm
	for (int i = 2; i * i <= limit; ++i)
		if (primes[i])
			for (int j = i + i; j <= limit; j += i)
				primes[j] = false;

	// print all found primes
	for (int i = 0; i <= limit; ++i)
	{
		if (primes[i])
		{
			printf("%d ", number);
		}
		number++;
	}
	delete[] primes;
	return 0;
}
