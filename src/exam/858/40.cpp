#include <stdio.h> 


size_t strlen2(const char* s) {
	const char* len = s;
	while (*len++);
	return len - s - 1;
}

void function(char* s, int n) {
	int len = strlen2(s);
	int i = len - 1;
   
	while (s[i] == '*') i--;
	if (len - i > n) s[i+n+1] = '\0';
}


int main() {
	char s[100];
	scanf("%s", &s);
	function(s, 2);
	
	printf("%s", s);
	return 0;
}


