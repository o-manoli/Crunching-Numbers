#ifndef STRUCTURED_ARRAY_H

#define STRUCTURED_ARRAY_H

#include <stddef.h>

typedef int Integer; // Element Alias

typedef struct {
	/*
		Just a heap allocated array with a length field
	*/

	size_t length;

	Integer array[]; // flexible array member allocation

} StructuredArray;

void print(StructuredArray* );

#endif // STRUCTURED_ARRAY_H

