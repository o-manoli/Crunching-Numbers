
#include "parse.h"

#include <stdio.h>
#include <stdlib.h>

int parse(int argc, char* argv[])
{
	/*
		- Check if help doc is required

		- Otherwise try parsing user input
			*this could fail
	*/

	for (int i = 0; i < argc; i++)
	{

		if (get_help(argv[i]))
		{
			printf(   // basically a heredoc
			"\tPrime Finding Programs\n" // strings concatenation
			"\t\tImplements the Sieve of Eratosthenes\n"
			"\n"
			"\tUsage:\n"
			"\t\tinput a number as ceil for the algorithm to look for primes\n"
			"\n"
			"\tCount:\n"
			"\t\tPipe into `| wc -l` to get the number of primes found\n"
			"\n"
			"\n" // this is still C. \n is mandatory!
			);
			exit(0);
		}
	}
	return (argc < 1) ? DEFAULT_CEIL : atoi(argv[0]);
}

