#include <iostream>

#define MAXSIZE 50

typedef int ElemType;

// 循环队列
typedef struct {
    ElemType data[MAXSIZE];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

// 还没看懂
bool EnQueue(SqQueue &Q, ElemType e) {
    if ((Q.rear + 1) % MAXSIZE == Q.front) {
        return false;
    }
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e) {
    if (Q.front == Q.rear) {
        return false;
    }
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAXSIZE;
    return true;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

