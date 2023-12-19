/*
	Author: @O-Manoli

	Sure looks cool.
	Not much useful really
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int index)
{
	// once i and j are initialized as *somewhat global variables bound this function
	static int i = -1, j = 1; // this instruction only gets executed once!
	// internal state achieved

	j = i + j;
	i = j - i;

	return j;
}

int main(int argc, char* argv[])
{
	unsigned int Up2 = 10;

	// input arg will be parsed as the last index
	if (argc > 1) Up2 = atoi(argv[1]);

	for (int index = 0; index <= Up2; index++)
		printf("%d\n", fibonacci(index));

	return 0;
}

