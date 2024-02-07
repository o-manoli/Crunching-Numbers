#include "primes.h"

#include<stdlib.h>
#include<stdbool.h>


int* sieve(int Up2)
{
	/*
		Returns a heap allocated array of prime numbers
	*/

	if (Up2 < 2) return (int*) calloc(1, sizeof(int));

	const int Size = (++Up2) >> 1;

	bool* const N = (bool*) calloc(Size, sizeof(bool));  // All numbers are assumed primes unless proven otherwise

	if (!N)   exit(1);

	bool* const Bound = Size + N;

	int p = 3;

	bool* i = N + 1, * F;

	while ((F = N + ((p * p) >> 1)) < Bound)
	{
		for (bool* n = F; n < Bound; n += p)   *n = 1;		// is not primes

		while ((p += 2) && *++i);
	}

	p = Size;

	bool* t = N;

	unsigned int P = 0;	// prime count

	while (p--)   P += !*t++;

	int* const Primes = (int*) malloc((P + 1) * sizeof(int));

	if (!Primes) exit(1);

	*Primes = P--;

	int* pt = Primes + 1;
	*pt = 2;

	t = N + 1;
	P = Size - 1;

	p = 1;

	while (P--)
		if ((p += 2) && !*t++) *++pt = p;

	free(N);

	return Primes;

}

