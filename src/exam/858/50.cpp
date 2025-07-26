#include <stdio.h>

int strlen(const char* str) {
	const char* a = str;
	while(*a++);
	return a - str - 1;
}

void function(char *ss) {
	int len = strlen(ss);
	for (int i = 0; i < len; i += 2) {
		if (ss[i] >= 'a' && ss[i] <= 'z') ss[i] -= 32;
	}
}

int main() {
	char str[] = "abc123ABC";
	function(str);
	printf("%s", str);
}
