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

		while(Up2--){
			static unsigned i = 0, j = 1;
			printf("%d\n", i);
			j = i + j;
			i = j -i;
		}

	return 0;
}

