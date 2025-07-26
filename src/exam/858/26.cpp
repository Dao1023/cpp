#include <stdio.h> 
#include <string.h> 

void function(char *s) {
	int len = strlen(s);
	int left = 0;
	int right = len - 1;
	
	while(left < right) {
		char temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		
		left++;
		right--;
	}
	
}

int main() {
	
	char s[] = "Dao1023";
	function(s);
	printf("%s", s);
	
	return 0;
}
