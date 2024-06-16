#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "primes.h"

void print(int P[])
{
	// P is an heap allocated array
	// with the capacity as the first value
	for (int n = *P++; n > 0; n--)
		printf("%d\n", *P++);
}

// if no ceil for the sieve is given via command line args
#define DEFAULT_CEIL 100

// strcmp returns zero if the strings are equal!
#define get_help(S) (strcmp(S, "--help") && strcmp(S, "-h"))
// get_help is 0 if neither option matches

int parse(int argc, char* argv[])
{
	/*
		- Check if help doc is required

		- Otherwise try parsing user input
			*this could fail
	*/

	for (int i = 0; i < argc; i++)
	{
		// !strcmp -> is a match
		// match -h or match match --help ==> get help
		// De Morgan's laws `not (A and B) = (not A) or (not B)`
		if (!get_help(argv[i]))
		{
			printf(   // basically a heredoc
			"\tPrime Finding Programs\n"
			"\t\tImplements the Sieve of Eratosthenes\n"
			"\n"
			"\tUsage:\n"
			"\t\tinput a number as ceil for the algorithm to look for primes\n"
			"\n"
			"\tCount:\n"
			"\t\tPipe into `| wc -l` to get the number of primes found\n"
			"\n"
			"\n"
				// this is still C. \n is mandatory!
			);
			exit(0);
		}
	}
	return (argc < 1) ? DEFAULT_CEIL : atoi(argv[0]);
}



int main(int argc, char* argv[])
{
	// first command line argument is the executable relative path
	int Up2 = parse(argc-1, argv+1); // so ignore that

	int* const Primes = sieve(Up2);

	print(Primes);

	// free(Primes);  // This is the OS job // **should be
	// hopefully it will be faster if the OS drops everything at the same time

	return 0;
}

