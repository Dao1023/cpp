#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 100

void function(char a[], char b[], int n) {
	int len = strlen(a);
	
	for (int i = 0; i < n - 1; i++) {
		b[i] = a[i];
	}
	for (int i = n - 1; i < len; i++) {
		b[i] = a[i + 1];
	}
	
	b[len - 1] = '\0';  // ����ַ���������
}


int main() {
	char a[] = "abcdef";
	char b[N];
	function(a, b, 3);
	
	// for (int i = 0; i < N; i++) {
	// 	 scanf("%c", &a[i]);
	// }
	
	printf("%s", b);
	
    return 0;
}


/*
#include <stdio.h>

void function(char a[], char b[], int n) {
    int i = 0, j = 0;

    // ����ԭ�ַ���
    while (a[i] != '\0') {
        if (i != n) {  // �����ǰ�±겻��Ҫɾ�����±�
            b[j] = a[i];  // ���ַ����Ƶ� b ��
            j++;
        }
        i++;
    }

    b[j] = '\0';  // �� b ��ĩβ����ַ���������
}

int main() {
    char a[] = "Hello, World!";  // ԭ�ַ���
    char b[100];  // �洢ɾ������ַ���
    int n = 7;  // ָ��Ҫɾ�����±�

    function(a, b, n);

    printf("ԭ�ַ���: %s\n", a);
    printf("ɾ���±� %d ����ַ���: %s\n", n, b);

    return 0;
}
*/
