#include <iostream>

#define MAXSIZE 50

typedef int ElemType;

// 顺序栈
typedef struct {
    ElemType data[MAXSIZE];     // 数组开存
    int top;    // 序号指针，而非地址指针
} SqStack;      // sequence stack

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack &S) {
    return S.top == -1;
}

bool StackFull(SqStack &S) {
    return S.top == MAXSIZE - 1;
}

// push 把元素推进栈里
bool Push(SqStack &S, ElemType e) {
    if (StackFull(S)) return false;
    S.data[++S.top] = e;
    return true;
}

// pop 弹出栈顶元素
bool Pop(SqStack &S) {
    if (StackEmpty(S)) return false;
    S.top--;
    return true;
}

bool GetTop(SqStack &S, ElemType &e) {
    if (StackEmpty(S)) return false;
    e = S.data[S.top];
    return true;
}

// 改指针位置后，相当于把已存内容不管了，正好和初始化功能是一样的
void FreeStack(SqStack &S) {
    S.top = -1;
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    int e;
    while (!StackEmpty(S)) {
        GetTop(S, e);
        std::cout << e << std::endl;
        Pop(S);
    }

    return 0;
}

