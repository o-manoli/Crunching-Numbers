#include "stdio.h"
#include "stdlib.h"

#define Number unsigned int

void print(Number* t) {
	int s = *t++;
	while (s--)
		printf("%d\n", *t++);
}

Number* sieve(const Number Up2) {

	if (Up2 < 2)
		return (Number*) calloc(0, sizeof(Number));

	const Number SIZE = (Up2 + 1) / 2;
	Number* const Re = (Number*) malloc((SIZE + 1) * sizeof(Number));
	Number* const BOUND = Re + SIZE;

	if (!Re)		exit(1);		// Memory DENIED!

	*Re = SIZE;

	// tmp
	Number* t, * s;		Number p, pp;

	// Aliases
	Number* const N = Re + 1;	// #cell-shift => start at 2

	// 1. Populate
	t = N;			*t++ = 2;

	if (Up2 < 3)	return Re;

	s = t;	*t++ = 3;	p = SIZE - 2;

	while (p--)
		*t++ = 2 + *s++;

	t = N + 1;
	do {	// 2. Eliminate

		p = *t;			pp = p * p;

		for (s = N + (pp >> 1); s <= BOUND; s += p) *s = 0;

		while (!*++t);

	} while (pp <= Up2);

	t = N;	s = t - 1;	p = BOUND - Re;

	while (p--)	// 3. Collect
		if (*++s)	*t++ = *s;

	*Re = t - N;

	return (Number*) realloc(Re, (t - Re) * sizeof(Number));
}

int main(int argc, char* argv[]) {

	int Up2 = (argc < 2) ? 7919	 : atoi(argv[1]);	// the 1000th prime

	Number* const Primes = sieve(Up2);

	if (argc > 2) {
		if (argv[2][0] == 'w')
			print(Primes);
	}
	else
		printf("\n\n\t%d Primes found Up to %d\n\n", *Primes, Up2);

	free(Primes);

	return 0;
}

