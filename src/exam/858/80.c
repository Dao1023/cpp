#include <stdio.h>

int main() {
	// int a;
	// printf("%d", a = 1);  // 赋值是有返回值的
	
	char ch;
	int count = 1;
	while ((ch = getchar()) != '\n') {
		if (ch == ' ') { count++; }
	}
	printf("%d", count);
}
