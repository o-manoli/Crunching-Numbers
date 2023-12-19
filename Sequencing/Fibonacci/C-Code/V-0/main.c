/*
	Author: @O-Manoli

	Sure looks cool.
	Not much useful really
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned int Up2 = 10;

	// input arg will be parsed as the last index
	if (argc > 1) Up2 = atoi(argv[1]);

	// 1, 2, 3, 4, 5, 6, 7, ... #index
	// 0, 1, 1, 2, 3, 5, 8, ...

	// the loop will stop when Up2 hits zero #new-year-countdown
	// Up2 will be decremented after checking that it's not zero

	for(int i = 0, j = 1; Up2--; j = i + j, i = j - i) // like an xor swap
		printf("%d\n", i);

	return 0;
}

