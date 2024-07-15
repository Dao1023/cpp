// 代码参考了下面，且修复了一些问题
// #include <527.3.cpp>

#define LIST_INIT_SIZE 100
typedef int ElemType;

// 最基础的线性表
typedef struct {
    ElemType data[50];
    int length;
} SqList;

// 动态分配想不起来了

void InitList(SqList &L) {
    L.length = 0;
}

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > LIST_INIT_SIZE) return 0;

    if (i > L.length) {
        L.data[i - 1] = e;
    } else {
        // j 就是索引，然后循环里面再对索引操作，好理解
        for (int j = L.length - 1; j >= i - 1; j--) {
            L.data[j + 1] = L.data[j];
        }
        L.data[i - 1] = e;
    }

    L.length++;
    return true;
}

// 这段代码写错了好几次，平时比如说 j++ 写成 i++
// 比如说 [j] [j+1] 写反了等，平时一定要注意
bool ListDelete(SqList &L, int i) {
    if (i < 1 || i > L.length) return 0;

    for (int j = i - 1; j <= L.length - 1; j++) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;

    return true;
}