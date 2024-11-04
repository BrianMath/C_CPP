#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
	uint64_t MaxLong = (1 << 64) - 1;
	uint64_t MaxLong1 = (uint64_t) (pow(2, 64) - 1);

	printf("%lu\n", MaxLong1);

	return 0;
}
