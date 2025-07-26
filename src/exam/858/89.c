#include <stdio.h>

void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
}

void insertSort(int a[], int len) {
        for (int i = 1; i < len; i++) {
		// i 是待排元素，[0, i-1] 是有序的
		int temp = a[i];
		int j = i - 1;
		while (j >= 0) {
			// 不断后移，然后把 a[i] 塞进去
			if (temp < a[j]) { a[j + 1] = a[j]; j--; } 
			else { break; }
		}
		a[j + 1] = temp;
        }
}

int main() {
        int a[] = {1, 3, 4, 2};   // 1342 1344 1334 1234
        int len = sizeof(a) / sizeof(a[0]);
        insertSort(a, len);
        for (int i = 0; i < len; i++) {
                printf("%d", a[i]);
        }
}
