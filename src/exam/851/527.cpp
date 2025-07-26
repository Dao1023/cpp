#include <iostream>
using namespace std;

int findMaxValue(int a[50], int k) {
    for (int i = 0; i < 50; i++) {
        if (a[i] == k) {return i;}
    }
    return -1;
}

// 时间复杂度 O(nlogn)，log(n)*i = log(n)*n
// j <= n 是函数相乘
int a_2014(int n) {
    int count = 0;
    for (int k = 1; k <= n; k *= 2) {
        for (int j = 1; j <= n; j++) {
            count++;
            cout << count << endl;
        }
        cout << endl;
    }
    return count;
}

// 时间复杂度 O(n)，log(i) = log(2^n) = n
// j < i 是复合函数
int a_2022(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i *= 2) {
        for (int j = 0; j < i; j++) {
            sum++;
        }
    }
    return sum;
}

int main() {
    int a, i;
    a = i++;    // 先赋值，再自加
    a = ++i;    // 先自加，再赋值


    cout << "i" << " " << "a_2014(10)" << "a_2022(i)" << endl;
    for (int i = 1; i <= 1024; i++) {
        cout << i << " " << a_2014(10) << a_2022(i) << endl;
    }
    return 0;
}
