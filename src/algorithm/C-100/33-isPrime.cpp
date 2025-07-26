#include <stdio.h> 
#include "string.h"

int isPrime(int m) {
	if (m <= 1) return 0;
	for (int i = 2; i < m; i++) {
		if (m % i == 0) return 0;
	}
	return 1;
}

int main() {
	int isPrime(int);
	
	int n = 17;
	// printf("%d\n", (int)sqrt((double)n));
	printf("%d\n", isPrime(n));
	
	return 0;
}
