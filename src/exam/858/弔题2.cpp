#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int compare(const void *a, const void *b) {
	double diff = (*(double *)b - *(double *)a);
	if (diff < 0) return -1;
	if (diff > 0) return 1;
	return 0;
}

// 逆序二分查找 
void binaryInsert(double arr[], int size, double target) {
	int left = 1;
	int right = size - 1;
	
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] > target) left = mid + 1;
		else right = mid - 1;
	}
	// return left;
	
	
	// 顺手插入 
	for (int i = 1; i <= left; i++) arr[i-1] = arr[i];
	arr[left] = target;
	
}

int main() {
	const int n = 3;
	double a[n] = {1, 9, 100};
	for (int i = 0; i < n; i++) printf("%lf, ", a[i]); printf("\n");
	
	/* 
	srand(time(NULL));      // 确保每次运行时种子不同
	for (int i = 0; i < n; i++) a[i] = rand() % 256;
	for (int i = 0; i < n; i++) printf("%lf, ", a[i]);
	*/
	
	qsort(a, n, sizeof(double), compare);
	for (int i = 0; i < n; i++) printf("%lf, ", a[i]); printf("\n");
	
	int P = 2;
	int Q = 0;
	for (int i = 0; i < P; i++) {
		a[0] = sqrt(a[0]);
		if (a[0] <= a[1]) binaryInsert(a, n, a[0]);
		for (int i = 0; i < n; i++) printf("%lf, ", a[i]); printf("\n");
	}
	for (int i = 0; i < Q; i++) {
		a[0] = a[0] / 2;
		if (a[0] <= a[1]) binaryInsert(a, n, a[0]);
	}
	
	
	
	
	
	
	return 0;
}
