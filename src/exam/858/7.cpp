#include <stdio.h>
#include <math.h>

#define N 100

// ��������ʲô�⣿ 

int main() {
	char s[N] = "**a*b*c*";
	int i;
	
	for (i = 0; i <= N; i++) {
		if (s[i] != '*') break;
	}
	for (; i <= N; i++) {
		printf("%c", s[i]);
	}
	
	return 0;
}
