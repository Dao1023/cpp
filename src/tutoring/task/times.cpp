#include <iostream>
using namespace std;

/*
输入 n，返回 1 到 n 中某个数字 x 出现的次数

例子：
输入 n=11 x=1
1 出现 1 次
10 出现 1 次
11 出现 2 次
总共是 4 次
*/
int count(int n, int x) {
    int count = 0;
    // 循环 1 到 n
    for (int i = 1; i <= n; i++) {

        // 每位的数字是否符合
        int num = i;
        while (num > 0) {
            if (num % 10 == x) {
                count++;
            }
            num /= 10;
        }
    }
    return count;
}

int main() {
    cout << count(11, 1) << endl;
}
