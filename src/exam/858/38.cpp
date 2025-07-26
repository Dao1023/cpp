#include <stdio.h> 


size_t strlen2(const char* s) {
	const char* len = s;
	while (*len++);
	return len - s - 1;
}

void function(char* s, char* t) {
	int j = 0;
	for (int i = 0; i < strlen2(s); i++) {
		if (i % 2 == 0 && s[i] % 2 == 0) t[j++] = s[i];
	}
}


int main() {
	char s[100];
	fgets(s, sizeof(s), stdin);
	char t[100];
	function(s, t);
	
	printf("%s", t);
	return 0;
}

