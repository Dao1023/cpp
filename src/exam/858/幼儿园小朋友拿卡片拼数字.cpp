#include <stdio.h> 


int main() {
	int ls[10];
	for (int i = 0; i < 10; i++) ls[i] = 2021;
	
	int num = 1;
	int flag = 1;
	int a;
	while (flag) {
		a = num;
		while (a > 0) {
			if(--ls[a % 10] < 0) flag = 0;
			printf("a: %d, num: %d\n", a, num);
			a /= 10;
		}
		num++;
	}
	printf("%d", num);
	
	// 以上代码比较暴力，聪明一点应该只统计 1 的使用情况 
}
