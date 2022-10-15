#define _CRT_SECURE_NO_WARNINGS
#define MAXSIZE 5
#include <stdio.h>

// 定义
typedef struct {
    int base;
    int top;
    int data[MAXSIZE];
}SqStack;

// 初始化
void InitStack(SqStack &S) {
    S.top = S.base;
}

// 入栈
int Push(SqStack &S, int e) {
    
}

// 出栈

// 判断栈空
int testSqStack(SqStack &S) {
    return (S.top == S.base);
}

// 判断栈满


int main() {
    int x;
    SqStack S;
    InitStack(S);
}