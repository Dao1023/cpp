#include <stdio.h> 


// 将一个字符串转换为一个整数
// 不得调用c语言提供的将字符串转换为整数的函数
int function(const char* s) {
	// 不知道题目是什么意思 ，是输出每个字符的 ASCII 吗 
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

