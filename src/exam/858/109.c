#include <stdio.h>

int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) { return 0; }
	}
	return 1;
}

int main() {
	// for (int i = 2; i < 100; i++) { if (isPrime(i)) printf("%d ", i); }

	int n = 6;
	while (n != 0) {
		int i = 2;
		if (n % i == 0) {
			printf("%d*", i);
			n /= 2;
		}
		else {
			// while (isPrime(i) == 0) i++;
			i++;
		}
	}
}
