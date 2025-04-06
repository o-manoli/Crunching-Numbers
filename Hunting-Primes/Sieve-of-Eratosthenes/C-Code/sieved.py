#!/usr/bin/env python3

from sympy import primerange

from sys import argv

def primes(Up2:int) -> list[int]:
	return list(
		primerange(Up2+1)
	) # type: ignore # not sufficient typing support in sympy as of now

def main():
	Up2:int = 100 if len(argv) == 1 else int(argv[1])

	print(
		*primes(Up2), sep="\n"
	)

if __name__ == "__main__":
	main()

