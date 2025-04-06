
#include "math.h"

Integer sqrt_floor(Integer number) {

	float target, low = 0.0f, high = target = (float) number;

	float pivot, epsilon = 0.5f;

	do {

		pivot = (low + high) / 2;

		if (pivot * pivot > target)
			high = pivot;
		else
			low = pivot;

	} while (high - low > epsilon);

	return pivot;

}
