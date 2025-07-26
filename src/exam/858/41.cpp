#include <stdio.h> 
#include <string.h>


// É¾³ý¿Õ¸ñ 
void function(char* s) {
	int j = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] != ' ') s[j++] = s[i];
	}
	s[j] = '\0';
}


int main() {
	char s[100];
	fgets(s, sizeof(s), stdin);
	int len = strlen(s);
	if (len > 0 && s[len - 1] == '\n')  s[len - 1] = '\0';
	
	function(s);
	
	printf("%s", s);
	return 0;
}


