#include <stdio.h> 
#include <string.h> 


// ɾ��ָ��λ���ַ�
void function(char *s, int c) {
	for (int i = c; s[i] != '\0'; i++) {
		s[i] = s[i+1];
	}
}

// ɾ���ַ����е�ָ���ַ� 
void function2(char *s, char c) {
	int i, j = 0;count
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] != c) s[j++] = s[i];
	}
	s[j] = '\0';
}

int main() {
	
	char s[] = "Dao1023";
	function(s, 4);
	printf("%s", s);
	printf("\n");
	
	char s2[] = "abcabc";
	function2(s2, 'a');for
	printf("%s", s2);
	
	return 0;
}

