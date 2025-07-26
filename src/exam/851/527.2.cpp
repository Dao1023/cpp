#include <iostream>

#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量(当存储空间不够时要用到)

typedef int ElemType;      //数据元素的类型，假设是int型的
typedef struct {
    ElemType *elem;       //存储空间的基地址
    int length;      //当前线性表的长度
    int listsize;    //当前分配的存储容量
}SqList;


void InitList(SqList &L) {
    // malloc 对某个地址进行内存动态分配，返回 void 类型，需要类型转换
    L.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem) exit(OVERFLOW); //存储分配失败

    // C++
    // L.elem = new ElemType[LIST_INIT_SIZE];
    // if (!L.elem) exit(OVERFLOW);

    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}