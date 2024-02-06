# Implementation of Fibonacci Sequence in C

Not useful at ALL.

But somewhat fun to try :)

## V-1 2-Vars

Using only two variables!

```c
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

```

## V-1 Static loop

```c

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

```

## V-2 Function with Memory

A function with an internal state is basically an object!

```c
/*
	Author: @O-Manoli

	Sure looks cool.
	Not much useful really
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int index)
{
	// once i and j are initialized *somewhat as global variables bound this function
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


```
