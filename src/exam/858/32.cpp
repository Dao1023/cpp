#include <stdio.h> 


// ��һ���ַ���ת��Ϊһ������
// ���õ���c�����ṩ�Ľ��ַ���ת��Ϊ�����ĺ���
int function(const char* s) {
	// ��֪����Ŀ��ʲô��˼ �������ÿ���ַ��� ASCII �� 
}


int main() {
	char str[100];
	fgets(str, sizeof(str), stdin);
	
	// �Ƴ����з���������ڣ�
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    
	printf("%d", function(str));	
	
	return 0;
}

