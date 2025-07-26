#include <stdio.h>

#define M 3
#define N 3

/*
1 2 3
4 5 6

1 2 3
4 5 6
7 8 9

1 2 3
4 5 6
7 8 9
0 1 2
*/


void function(int a[M][N], int m) {
	for (int i = 0; i < M; i++) {
		for (int j = N - 1; j >= i; j--) {
			a[i][j] *= m;
		}
	}
}

 
int main() {
	int a[M][N] = {{1,2,3}, {4,5,6}, {7,8,9}};
	function(a, 2);
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d, ", a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
