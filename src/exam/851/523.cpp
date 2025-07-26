#include <iostream>
using namespace std;

#define MaxSize 50

/*
常见的 sizeof
int 4
*/

int func01(SqList &L) {
    if (L.length == 0) {
        return 0;
    }

    int min = L.data[0];
    int k;
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] < min) {
            min = L.data[i];
            k = i;
        }
    }

    L.data[k] = L.data[length-1];
    L.length--;
    return min;
}

int swap(int x, int y) {
    // ...
    return x < y ? x : y;
}

int func02(SqList &L) {
    int left = 0;
    int right = L.length -1;

    while (left <= right) {
        swap(L.data[left], L.data[right]);
    }

    // 方法2
    for (int i = 0; i<L.length/2; i++) {
        // ...
    }

}

int func03(SqList &L) {
    for (int i = 0; i<L.length; i++) {
        
    }
}


int main() {
    typedef Elemtype int;
    typedef struct {
        Elemtype data[MaxSize];
        int length;
    }SeqList;

}