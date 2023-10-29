r"""

	All combination of groups element

	```python
	A = True, False
	B = 1, 2, 3
	C = "ABC"

	for V in cycle(A, B, C):
		print(*V, sep='\t')

	# So basically the same as using itertools.product

	print(14*"- ")

	import itertools

	for V in itertools.product(A, B, C, repeat=1):
		print(*V, sep='\t')
	```

	The idea is to build all possible combination by taking one element from each group
		and building all possible varieties of that choice
	So we should be able to isolate one group from the others and observe its effect on the resulting combinations.
		We will see that each element from that set is paired same subset of combinations
			which it self represent subsets of n-1 group
			and so on until there is only one set left to consider
	The Complexity of the repeating this process can be reduced by just cycling each element
		in a group N times where N is the product of the group-size to the right
"""

from typing import Iterable, Any, Iterator, Sequence

def repeatCycle(A: Iterable[Any], times:int) -> Iterator[Any]:
	yield from (a for a in A for _ in range(times))

def loopCycle(A: Iterable[Any], times:int) -> Iterator[Any]:
	while True:
		yield from (a for a in A for _ in range(times))

def cycle(A: Iterable[Any], *B: Sequence[Any]):
	InternalState = [1]
	def M(X: Sequence[Any], S:list[int] = InternalState):
		S.append(S[-1] * len(X))
		return loopCycle(X, S[-2])
	O = *map(M, B), repeatCycle(A, InternalState[-1])
	return zip(*O[::-1])

if __name__ == '__main__':
	print(__doc__)

