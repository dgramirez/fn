#define _CRT_SECURE_NO_WARNINGS
#include "rng_xoroshiro128plus.hxx"
#include <stdio.h>

int main() {
	printf("How many: ");

	int x = 0;
	scanf("%d", &x);

	printf("Getting %d amount...\n", x);

	uint64_t state_64 = x;
	uint64_t state_128[2];
	state_128[0] = splitmix64_next(&state_64);
	state_128[1] = splitmix64_next(&state_64);

	uint64_t v = 0;
	for (int i = 1; i <= x; ++i) {
		// Last 4 Bits not reliable, so remove
		v = xoroshiro128plus_next(state_128) >> 4;
		printf("    #%d: %llu\n", i, v);
	}

	return 0;
}
