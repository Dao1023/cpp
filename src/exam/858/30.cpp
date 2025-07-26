#include <stdio.h> 
#include <string.h> 


// СС�Ľ���һ�� 
void swap(char* a, char* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// ���������ַ� 
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
	
	// �Ƴ����з���������ڣ�
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
	function(str);
	printf("%s", str);	
	
	return 0;
}

