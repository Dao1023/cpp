/*
x+y 有多少个组合
1-10 的姐妹数

在不同时取一个数的情况下

两个数的组合 (x,y) 有多少
(1,2) (1,3) (1,4) ... (1,10)
(2,3) (2,4) (2,5) ... (2,10)
...
(9,10)

1<=x<=9
x<=y<=10

组合数
1-n 中，两两组合，有多少种组合
m 组合，有多少种组合
*/

#include <iostream>
using namespace std;


int main() {
    int n=10;

    for (int i=1; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            cout << "(" << i << "," << j << ")" << " ";
        }
        cout << endl;
    }
    return 0;
}

