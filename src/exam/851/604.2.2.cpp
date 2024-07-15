#include <iostream>

#define MAXSIZE 50

typedef int ElemType;


// 链栈
typedef struct node {
    ElemType data;
    struct node* next;
} Node;

typedef struct {
    Node* top;
} yyy;


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

