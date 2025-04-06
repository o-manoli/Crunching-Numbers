
#include <stdlib.h>

#include "src/parse.h"
#include "src/primes-sieve.h"
#include "src/structured-array.h"

int main(int argc, char* argv[])
{
	// first command line argument is the executable relative path
	int Up2 = parse(argc-1, argv+1); // so ignore that

	StructuredArray* primes = sieve(Up2);

	print(primes);

	// free(primes);  // This is the OS job // **should be
	// hopefully it will be faster if the OS drops everything at the end

	return 0;
}
