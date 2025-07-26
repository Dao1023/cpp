// 静态顺序表的实现

#include <iostream>

#define LIST_INIT_SIZE 100


typedef int ElemType;
typedef struct {
    ElemType data[LIST_INIT_SIZE];
    int length;
} SqList;


int InitList(SqList &L) {
    L.length = 0;
    return 1;
}

// 算法复杂度最好O(1) 最差O(n) 平均O(n/2)
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return 0;    // 此处的 i 是第几位，而非下标，范围 1~length
    if (L.length >= LIST_INIT_SIZE) return 0;

    for (int j = L.length; j >= i; j--) {   // length~i 全部后挪
        L.data[j + 1 - 1] = L.data[j - 1];  // 这样写只是方便理解
    }
    L.data[i - 1] = e;
    L.length++;

    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return 0;
    if (L.length == 0) return 0;

    e = L.data[i - 1];
    for (int j = i; j <= L.length; j++) {   // i~length 全部前挪
        L.data[j - 1] = L.data[j];      // 代码补全是 j-2 排查了一个小时怎么都对不上，气死
    }
    L.length--;

    return true;
}

int LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i + 1;
    }
    return 0;
}

int main() {


    std::cout << "Hello, World!" << std::endl;
    return 0;
}