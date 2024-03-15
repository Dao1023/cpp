#include <stdio.h>

int add(int a, int b) {
	return a + b;
}

int multi(int a, int b) {
	return a * b;
} 

double area(double a, double h) {
	return a * h / 2;
}

void print_array(int* a) {
	
}

int main() {
	printf("%d\n", add(100, 20));
	printf("%d\n", multi(100, 20));
	printf("%lf\n", area(10, 6.5));
	
	return 0;
}
