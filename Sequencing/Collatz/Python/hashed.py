"""
	Collatz Sequence
	Implemented using Python dictionaries as a hash map
"""

import sys
from collections import deque

def sequence_length(
	x:int,
	L:dict[int, int] = {1:1},	# Link Map
	V:dict[int, int] = {1:1},	# Value Map
	M:deque[int] = deque()
	) -> int:

	X = x

	while L.get(x) is None:
		L[x], x = (y:= 3 * x + 1 if x & 1 else x // 2), y

	x = X

	while V.get(x) is None:
		M.append(x)
		x = L[x]

	while len(M):
		x = M.pop()
		V[x] = 1 + V[L[x]]

	return V[X]


def main(x:int):
	print(f"\nCollatz Sequence Length of {x}: {sequence_length(x)}\n")

if __name__ == '__main__':
	if len(sys.argv) < 2:
		print(__doc__)
		exit(1)
	for x in map(int, sys.argv[1:]):
		main(x)
