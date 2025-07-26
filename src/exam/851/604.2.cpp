#include <iostream>

#define MAXSIZE 50

typedef int ElemType;

// 共享栈
typedef struct {
    ElemType data[MAXSIZE];
    int top[2];
} ShareStack;

void InitStack(ShareStack &S) {
    S.top = -1;
    S.bottom = MAXSIZE - 1;
}

int Push(ShareStack &S, ElemType e, int i) {
    if (i < 0 || i > 1) return 0;
    if (S.top[1] - S.top[0] == 1) return 0;

    switch (i) {
        case 0: S.data[S.top[0]++] = e; break;
        case 1: S.data[S.top[1]--] = e; break;
    }
    return 1;
}

ElemType Pop(ShareStack &S, int i) {
    if (i < 0 || i > 1) return -1;

    switch (i) {
        case 0: return S.data[--S.top[0]];
        if (S.top[i] == -1) return -1;
        case 1: return S.data[++S.top[1]];
    }
    return 0;

    ElemType e = S.data[S.top[i]];
    S.top[i]--;
    return e;
    }
    return 0;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

