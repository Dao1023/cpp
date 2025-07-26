// 单链表的实现

#include <iostream>

typedef int ElemType;
typedef struct {
    ElemType data;      // 链表体
    struct LNode *next; // 链表尾
} LNode, *LinkList;     // 两个名字


bool InitList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));    // 头结点
    if (!L) return false;

    // L -> data = 0;
    L -> next = NULL;   // (*L).next 的简化写法

    return true;
}

bool ListInsert(LinkList &L, int i, ElemType e) {

}
