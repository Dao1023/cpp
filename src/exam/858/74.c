#include <stdio.h>

int gcd (int a, int b) {
	if (a < b) {
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

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}


int main() {
	printf("%d", lcm(6, 8));
}
