#include <stdio.h>
#include <math.h>


// 如果不单独写，还可以用 for 循环的 break 弹出 
int isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}

double function(int n) {
	double s = 0.0;
	for (int i = 3; i <= n; i++) {
		if (isPrime(i)) s += pow(i, 0.5);
	}
	return s;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%f", function(n));
	
	return 0;
}
