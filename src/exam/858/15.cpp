#include <stdio.h>
#include <math.h>


void function(int x, int pp[], int *n) {
	int k = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0 && i % 2 != 0) {
			pp[k++] = i;
		}
	}
	*n = k;
}


int main() {
	int pp[10];
	int n;
	function(5, pp, &n);
	printf("%d", n);
	
    return 0;
}

