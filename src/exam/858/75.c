#include <stdio.h>

int fun(int n) {
	int arr[10];
	int i = 0;
	while (n > 0) {
		arr[i++] = n % 10;
		n /= 10;
	}
	int j = 0;
	while (i > 0) {
		if (arr[--i] != arr[j++]) return 0;
	}
	return 1;
}

int main() {
	int n = 256;
	for (int i = 1; i < n; i++) {
		int result = fun(i * i);
		if (result) { printf("%d, ", i); }
	}
}
