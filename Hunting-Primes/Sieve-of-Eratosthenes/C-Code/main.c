#include <stdio.h>
#include <stdlib.h>

#include "primes.h"

void print(int* P)
{
	for (int n = *P++; n > 0; n--)
		printf("%d\n", *P++);
}

int main(int argc, char* argv[])
{
	int Up2 = (argc < 2) ? 100 : atoi(argv[1]);

	int* const Primes = sieve(Up2);

	print(Primes);

	free(Primes);

	return 0;
}

