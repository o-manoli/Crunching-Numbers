#!/usr/bin/env python3

r"""
	Implementing The Sieve of Eratosthenes

	Using Python and Numpy

	Source: https://t5k.org/howmany.html

	Usage:
		- <n> a number, up to which primes will be sieved out
		- p to write to the terminal
		- w to write to disk
			- npy to write as *.npy file

		Order doesn't matter

"""

import sys
import time
import numpy
import typing
import functools

def timeit(f:typing.Callable) -> typing.Callable:
	@functools.wraps(f)
	def wrapper(*args, **kwargs):
		start = time.perf_counter()
		result = f(*args, **kwargs)
		end = time.perf_counter()
		T = end - start
		print(f"\n\n\tFunction {f.__name__}{args} {kwargs} Took {T:.6f} seconds ...\n")
		return result
	return wrapper

def I(i:int) -> int:
	return (i - 3)//2 + 1

Ix = numpy.vectorize(I)

def multiple(Up2:int, p:int) -> numpy.ndarray:
	return Ix(p * numpy.arange(p, Up2//p + 1, 2, dtype=int))

@timeit
def sieve(Up2:int) -> numpy.ndarray:

	if Up2 < 2:
		return numpy.asarray([])

	M = functools.partial(multiple, Up2)

	N = numpy.arange(1, Up2+1, 2, dtype=int)
	N[0] = 2
	p = 3

	while p**2 < Up2:
		N[M(p)] = 0
		i = I(p) + 1

		while N[i] == 0:
			i += 1

		p = N[i]

	return N[numpy.nonzero(N)]

def main(N:int, output:bool, write:bool = False, npy:bool = False):

	A = sieve(N)
	print(f"\n\tPrimes found Up to {N} : {A.size}\n\n")

	if output:
		print(*A, sep="\n", end=2*"\n")

	if not write:
		return

	filename = f"Primes-{A.size}"

	if npy:
		return numpy.save(filename, A)

	with open(f"{filename}.txt", "w") as out:
		print(*A, sep="\n", file=out)

if __name__ == '__main__':

	Args = sys.argv[1:]

	for a in Args:
		try:
			N = int(a)
			break
		except ValueError:
			continue		# try and fail
	else:
		print(__doc__)
		exit(1)

	main(N, "p" in Args , "w" in Args, "npy" in Args)

