#include <stdio.h>

int main() {
	int a = 1;
	for (int i = 10; i > 1; i--) {
		printf("%d, %d\n", i, a);
		a += 1;
		a *= 2;
	}

	printf("%d", a);
}