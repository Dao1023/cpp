#include <stdio.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortBySelect(int a[], int len) {
	int min;
	for (int i = 0; i < len; i++) {
		min = i;
		for (int j = i + 1; j < len; j++) {
			if (a[min] > a[j]) min = j;
		}
		if (min != i) swap(&a[min], &a[i]);
	}
}

int main() {
	int a[] = {2, 1, 4, 3};
	int len = sizeof(a) / sizeof(a[0]);
	sortBySelect(a, len);
	for (int i = 0; i < len; i++) { printf("%d ", a[i]); }
}
