#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 100

void function(char a[], char b[], int n) {
	int len = strlen(a);
	
	for (int i = 0; i < n - 1; i++) {
		b[i] = a[i];
	}
	for (int i = n - 1; i < len; i++) {
		b[i] = a[i + 1];
	}
	
	b[len - 1] = '\0';  // 添加字符串结束符
}


int main() {
	char a[] = "abcdef";
	char b[N];
	function(a, b, 3);
	
	// for (int i = 0; i < N; i++) {
	// 	 scanf("%c", &a[i]);
	// }
	
	printf("%s", b);
	
    return 0;
}


/*
#include <stdio.h>

void function(char a[], char b[], int n) {
    int i = 0, j = 0;

    // 遍历原字符串
    while (a[i] != '\0') {
        if (i != n) {  // 如果当前下标不是要删除的下标
            b[j] = a[i];  // 将字符复制到 b 中
            j++;
        }
        i++;
    }

    b[j] = '\0';  // 在 b 的末尾添加字符串结束符
}

int main() {
    char a[] = "Hello, World!";  // 原字符串
    char b[100];  // 存储删除后的字符串
    int n = 7;  // 指定要删除的下标

    function(a, b, n);

    printf("原字符串: %s\n", a);
    printf("删除下标 %d 后的字符串: %s\n", n, b);

    return 0;
}
*/
