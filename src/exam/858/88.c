#include <stdio.h>

void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}

void sortByPop(int a[], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (a[i] > a[j]) swap(&a[i], &a[j]);
		}
	}
}

int main() {
	int a[] = {2, 1, 4, 3};
	int len = sizeof(a) / sizeof(a[0]);
	sortByPop(a, len);
	for (int i = 0; i < len; i++) {
		printf("%d", a[i]);
	}
}
