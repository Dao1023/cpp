#include <stdio.h> 
#include <string.h> 


// 不支持合法区间检测
// 不支持多区间的空隙检测 
int main() {
	
	int min = 1e10, max = -1e10;
	int a, b;
	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		scanf("%d", &b);
		
		if (a < min) min = a;
		if (b > max) max = b;
	}
	
	printf("%d, %d", min, max);
		
	return 0;
}

