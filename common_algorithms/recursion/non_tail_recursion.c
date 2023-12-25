//non tail recursion
#include <stdint.h>
#include <stdio.h>

uint64_t factorial(uint64_t n) {
	if (n == 0) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	uint64_t res = factorial(20);
	printf("%lld", res);
	return 0;
}