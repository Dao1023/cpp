/**
 * 队列是重要的工具，在后续遍历时经常用到
 */

#define Maxsize 50
typedef int ElemType;

typedef struct {
    ElemType data[Maxsize];
    int front, rear;
} SqQueue;



void InitQueue(SqQueue &Q) {
    // Q.front = Q.rear = Q;   // 学姐的写法，代码报错了
    Q.front = Q.rear = 0;   // 书上的方案
}

bool isEmptyQueue(SqQueue Q) {
    if (Q.front == Q.rear) return true;
    else return false;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % Maxsize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    return true;
}

