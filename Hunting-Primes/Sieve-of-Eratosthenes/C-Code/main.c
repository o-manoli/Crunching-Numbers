#include "stdio.h"
#include "stdlib.h"

void print(int *t){
	int s = *t++;
	while(s--)
		printf("%d\n", *t++);
}

int *sieve(const int Up2){

	if (Up2 < 2)
		return calloc(0, sizeof(int));

	const int SIZE = (Up2+1)/2;
	int* const Re = malloc( (SIZE+1) * sizeof(int));
	*Re = SIZE;


	// tmp
	int S;		int *t, *s;

	// Aliases
	int* const N = Re +1;	// #cell-shift => start at 2

	// 1. Populate
	t = N;
	*t++ = 2;	s = t;	*t++ = 3;

	S = SIZE-2;	// start loop at cell 5
	while(S--)
		*t++ = 2 + *s++;

	// 2. Eliminate

	int p = 3;	int p2;
	t = N+1;

	while(p*p <= Up2){

		p2 = p<<1;		// cache 2*p

		for (int i = p*p; i <= Up2 ; i += p2)
			N[i>>1] = 0;

		while (!*++t);
		p = *t;
	}

	S = SIZE;	t = N;	s = t-1;

	while(S--)
		if (*++s)	*t++ = *s;

	*Re = t - N;
	return realloc(Re, (t - Re) * sizeof(int));
}

int main(int argc, char* argv[]){

	int Up2 = (argc < 2) ? 7919 : atoi(argv[1]);	// the 1000th prime

	int* const primes = sieve(Up2);

	if (argc > 2){
		if (argv[2][0] == 'w')
			print(primes);
	} else
		printf("\n\n\t%d Primes found Up to %d\n\n", *primes, Up2);

	free(primes);

	return 0;
}

