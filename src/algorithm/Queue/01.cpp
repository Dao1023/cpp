#define SIZE 20

typedef struct queue {
    int arr[SIZE];
    int front;
    int rear;
    int counter;

} Queue;

void Init(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->counter = 0;
}

bool IsFull(Queue* q) {
    return (q->counter >= SIZE);
}

void EnQueue(Queue* q, int val) {
    if (IsFull(q))
        return;

    q->rear = (q->rear + 1) % SIZE;
    q->arr[q->rear] = val;
    q->counter++;
}

bool IsEmpty(Queue* q) {
    return (q->counter <= 0);
}

void DeQueue(Queue* q) {
    if (IsEmpty(q))
        return;

    q->front = (q->front + 1) % SIZE;
    q->counter--;
}

// get the front element from queue
int Front(Queue* q) {
    if (IsEmpty(q))
        return;

    return q->arr[q->front];
}