// 引入头文件
#include <iostream>
using namespace std;

int helloworld() {
    cout << "hello world" << endl;
    return 0;
}

int hellohello() {
    cout << "hello hello" << endl;
    return 0;
}

int add(int a, int b) {
    return a*b;
}

// 写一个主函数作为程序的入口
int main() {
    cout << add(add(3, 2), 2) << endl;
    return 0;
}