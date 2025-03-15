
// {1, 2, 3, 4, 1}
// 对某个一维数组，寻找连续的 k 个数字，使之最大
// 滑动窗口，O(n) 

#include <stdio.h> 


// V0.1：能用 
int main() {
	int a[] = {1, 2, 3, 4, 1};
	int k = 3;
	
	int len = sizeof(a) / sizeof(a[0]);
	int max = 0, windows, index, j;
	for (int i = 0; i < len - k; i++) {
		windows = 0;
		for (j = i; j < i + k; j++) windows += a[j];
		if (max < windows) {	
			max = windows;
			index = --j;
		}
	}	
	
	for (int i = index; i > index - k; i--) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("max = %d", max);

	return 0;
}

/*
// V0.2，把部分重复计算的踢掉 
int main() {
	int a[] = {1, 2, 3, 4, 1};
	int k = 3;
	
	int len = sizeof(a) / sizeof(a[0]);
	int max = 0, windows, index, j;
	for (int i = 0; i < len - k; i++) {
		windows = 0;
		
		for (j = i; j < i + k; j++) {
			if (窗口头下一个比尾部小) continue;
			windows += a[j];
		}
		if (max < windows) {	
			max = windows;
			index = --j;
		}
	}	
	
	for (int i = index; i > index - k; i--) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("max = %d", max);

	return 0;
}
*/


