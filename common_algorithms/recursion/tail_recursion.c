//tail recursion
#include <stdint.h>
#include <stdio.h>

uint64_t factorial(uint64_t n, uint64_t acc) {
	if (n == 0) {
		return acc;
	}
	return factorial(n - 1, acc * n);
}

int main() {
	uint64_t res = factorial(20, 1);
	printf("%lld", res);
	return 0;
}