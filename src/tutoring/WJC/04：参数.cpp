#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("���ṩ���������ַ�����Ϊ������\n");
        return 1;
    }

    int length = 0;
    for (int i = 1; i < argc; i++) {
        length += strlen(argv[i]);
    }
    char result[length + 1];
    result[0] = '\0';
    for (int i = 1; i < argc; i++) {
        strcat(result, argv[i]);
    }
    printf("ƴ�Ӻ���ַ�����: %s\n", result);
    return 0;
}
