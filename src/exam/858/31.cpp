#include <stdio.h> 
#include <string.h> 



// 判断是否为回文字符串
int function(const char* s) {
	int left = 0;
	int right = strlen(s) -1;
	
	while (left < right) {
		if (s[left] != s[right]) return 0;
		left++;
		right--;
	}
	return 1;
}


int main() {
	char str[100];
	fgets(str, sizeof(str), stdin);
	
	// 移除换行符（如果存在）
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
	printf("%d", function(str));	
	
	return 0;
}

