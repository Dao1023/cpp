#include <stdio.h>

int swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

size_t strlen(char* s) {
	char* t = s;   // 定义 t 给 t 赋值为 s
	while(*t++);
	return t - s - 1;
}

int main() {
	
}
