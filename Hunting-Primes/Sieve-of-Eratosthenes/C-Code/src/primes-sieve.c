
#include "primes-sieve.h"
#include "math.h" // local library not <math.h>

#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


StructuredArray* sieve(Integer Up2)
{
	if (Up2 < 2)
		return calloc(1, sizeof(StructuredArray));

	// / 2 is optimized to bit shift in most modern compiler anyway
	Integer candidates_count = (Up2+1) >> 1; // how many odd integers <= Up2

	bool* candidates = calloc(
		candidates_count +1, // as padding to force stop loop
		sizeof(bool)
	);
	assert(candidates != NULL && "Candidates MEMORY DENIED!");

	bool* BOUND = candidates + candidates_count;

	candidates[0] = true; // 1 is not a prime

	Integer p = 3;   bool* index = candidates +1;

	Integer UPPER_BOUND = sqrt_floor(Up2); // largest number that can be squared whilst still less than Up2

	while (p <= UPPER_BOUND)
	{
		// eliminate odd multiple of p
		for (
			bool* n = candidates + ((p*p) >> 1); // foothold
			n < BOUND;
			n += p
		) *n = true;

		// look for next prime
		do { p += 2; index++; } while (*index == true); // last value is guaranteed to be false!
	}

	// count non zero values
	Integer primes_count = 0;

	// first value is 1. #throwaway
	for (bool* n = candidates; ++n < BOUND; primes_count += !*n); // ! is logical negation with an output of 0 or 1

	StructuredArray* primes = malloc(
		sizeof(StructuredArray)
		+ (primes_count + 1 +1) * sizeof(Integer) // one extra spot as safety cochin
	);
	assert(primes != NULL && "Primes MEMORY DENIED!");

	primes->length = primes_count + 1;
	Integer* P = primes->array;

	*P++ = 2;	p = 3;

	for (
		bool* n = candidates;
		++n < BOUND;
		p += 2
	) {
		*P = p;
		P += !*n; // increment if it was a prime
		// otherwise keeps hammering same spot
	}

	return primes;
}

