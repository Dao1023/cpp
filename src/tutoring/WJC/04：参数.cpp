#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("请提供至少两个字符串作为参数。\n");
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
    printf("拼接后的字符串是: %s\n", result);
    return 0;
}
