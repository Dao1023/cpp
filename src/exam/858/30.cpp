#include <stdio.h> 
#include <string.h> 


// 小小的交换一下 
void swap(char* a, char* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 降序排序字符 
void function(char* s) {
	int len = strlen(s);
	if (len <= 2) return;
	
	int max;
	for (int i = 1; i <= len - 2; i++) {
		max = i;
		for (int j = i + 1; j <= len - 2; j++) {
			if (s[j] > s[max]) max = j;
		}
		if (max != i) swap(&s[i], &s[max]);
	}
}


int main() {
	char str[100];
	fgets(str, sizeof(str), stdin);
	
	// 移除换行符（如果存在）
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
	function(str);
	printf("%s", str);	
	
	return 0;
}

