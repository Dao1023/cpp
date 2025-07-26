/**
 * 动态分配空间的版本，避免了 MaxSize 写死
 */


#include <iostream>
#include <cstdlib>
#include <ctime>

typedef std::time_t ElemType;

typedef struct {
    ElemType *data;
    int front, rear;
    int maxSize;
} SqQueue;



void InitQueue(SqQueue &Q, int size) {
    Q.data = (ElemType*)malloc(size * sizeof(ElemType));
    if (Q.data == nullptr) {
        std::cerr << "Memory allocation failed." << std::endl;
        exit(1);
    }
    Q.front = Q.rear = 0;
    Q.maxSize = size;
}

bool isEmptyQueue(SqQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % Q.maxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Q.maxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Q.maxSize;
    return true;
}

void DestoryQueue(SqQueue &Q) {
    free(Q.data);
    Q.data = nullptr;
    Q.front = Q.rear = Q.maxSize = 0;
}
