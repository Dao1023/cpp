#include <stdio.h>
#include <math.h>


double func(int x, int n) {
	double a = 1.0;
	double b = 1.0;
	for (int i = 1; i <= n; i++) {
		b *= i;
		a += pow(x, i) / b;
	}
	return a;
}

int main() {
	
	printf("%f", func(2, 3));
	return 0;
}
