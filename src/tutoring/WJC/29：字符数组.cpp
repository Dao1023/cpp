#include <stdio.h>
#include <string.h>

int main() {
	int a = 3;
	int b[] = {1, 3, 5, 7, 9};
	
	char c = 'v';
	char d[] = "Dao";
	
	printf("%d\n", a);
	for (int i = 0; i < 5; i++) printf("%d, ", b[i]); printf("\n");
	printf("ascii: %c\n", c);
	printf("Hello, %s", d);
		
	return 0;
}
