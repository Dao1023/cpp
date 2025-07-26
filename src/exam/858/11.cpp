#include <stdio.h>
#include <math.h>

// sn=(1-1/2)+(1/3-1/4)+…+(1/(2n-1)1/2n)
// 注意看通项公式 
double func(int n) {
	double sn = 0.0;
	for (int i = 1; i <= n; i++) {
		sn += 1.0 / (2*i-1) - 1.0 / (2*i);
	}
}

int main() {
	printf("%lf", func(1));
	return 0;
}
