#include <stdio.h>

int gcd(int a, int b) {
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int a = 12;
	int b = 18;
	int c = gcd(a, b);
	
	printf("%d\n", c);
}
