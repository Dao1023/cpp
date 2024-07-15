#include "SqList.h"
#include <iostream>
using namespace std;


// 最简单版本
// int Search_Sq(SqList L, int key) {
//     for (int i = 0; i < L.length; i++) {
//         if (L.data[i] == key) {
//             return i + 1;
//         }
//     }
//     return -1;
// }

// 稍微动点脑子版本
// 注意！这个版本的顺序表中 data[0] 不要存数据，哨兵要站着
int Search_Sq(SqList L, int key) {
    L.data[0] = key;
    for (int i = L.length; L.data[i] != key; i--)
        return i;
}

int 


int main() {
    // 创建顺序表部分，我就紧凑地写了
    SqList L;
    InitList(L);
    ListInsert(L, 2, 0);
    ListInsert(L, 3, 7);
    ListInsert(L, 4, 2);
    ListInsert(L, 5, 1);
    for (int i = 0; i < L.length; i++) { cout << L.data[i]; }
    cout << endl;
    ListDelete(L, 2);
    for (int i = 0; i < L.length; i++) { cout << L.data[i]; }
    cout << endl;
}