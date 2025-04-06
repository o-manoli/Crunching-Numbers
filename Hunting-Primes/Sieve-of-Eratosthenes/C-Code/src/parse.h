#ifndef PARSE_H_

#define PARSE_H_

#include <string.h>

// if no ceil for the sieve is given via command line args
#define DEFAULT_CEIL 100

// strcmp returns zero if the strings are equal!
#define get_help(S) (!(strcmp((S), "--help") && strcmp((S), "-h")))
// !strcmp -> is a match
// match -h or match match --help ==> get help
// De Morgan's laws `not (A and B) = (not A) or (not B)`
// get_help is 0 if neither option matches

int parse(int argc, char* argv[]);

#endif // PARSE_H_

