#include <iostream>

using namespace std;

int main() {
    int x;      // 创建地址，int 分配 4B
    cout << &x << endl;     // & 是取地址，是 int* 地址数据类型
    x = 10086;  // 存储数据
    cout << x << endl;

    int* p = &x;            // 创建地址变量 int*
    cout << p << endl;      // p 的值就是 x 的地址
    cout << &p << endl;     // &p 是 p 的地址
    cout << &x - (int*) &p << endl;  // 要转化 * - ** 为 * - *
    cout << *p << endl;     // * 是取值，*p 是 x 的值
    cout << **&p << endl;   // 故意考你，**&p 是 x 的值

    int a = *p;
    cout << a << endl;
}
