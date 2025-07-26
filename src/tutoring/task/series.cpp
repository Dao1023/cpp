// 引入头文件
#include <iostream>
using namespace std;

int function(int a1, int d, int n) {
    return a1 + d*(n-1);
}

// 写一个主函数作为程序的入口
int main() {
    cout << "a10 = " << function(1, 3, 10) << endl;
    cout << "a15 = " << function(1, 3, 15) << endl;
    cout << "a20 = " << function(1, 3, 20) << endl;
    cout << "a25 = " << function(1, 3, 25) << endl;
    cout << "a30 = " << function(1, 3, 30) << endl;
}