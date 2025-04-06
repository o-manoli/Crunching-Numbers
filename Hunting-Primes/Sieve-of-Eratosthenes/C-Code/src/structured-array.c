
#include "structured-array.h"

#include <stdio.h>

void print(StructuredArray* A)
{
	for (unsigned int i = 0; i < A->length; i++)
		printf("%d\n", A->array[i]);
}
