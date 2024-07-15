#include <stdio.h>
#include <math.h>

double func(int m) {
	double s = 0.0;
	for (int i = 1; i <= m; i++)  s += log(i);
	return pow(s, 0.5);
}

int main() {
	printf("%lf", func(1));
	return 0;
}
