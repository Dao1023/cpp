#include <stdio.h>

void run(int n) {
	char value;
	if (n == 0) {
		value = getchar();
		putchar(value);
	} else {
		value = getchar();
		run(n-1);
		putchar(value);
	}
}

int main() {
	run(5);
	return 0;
}
