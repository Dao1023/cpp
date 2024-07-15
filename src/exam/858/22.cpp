#include <stdio.h>
#include <math.h>



void function(int a[][3], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			a[i][j] = 0;
		}
	}
}

int main() {
	int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	function(a, 3);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
    return 0;
}
 
