#include <iostream>
using namespace std;

// 判断质数
int prime(int number) {
    if (number <= 1) {
        return 0;
    } else if (number == 2) {
        return 1;
    } else if (number % 2 == 0) {
        return 0;
    } else {
        for (int i=3; i<=number/2; i+=2) {
            if (number % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

// 判断质数（简单版）
int prime2(int number) {
    for (int i=2; i<number; i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // 遍历 1-20 判断
    // for (int i=1; i<=200; i++) {
    //     cout << i << ": " << prime(i) << endl;
    // }
    
    for (int i=1; i<=100000; i++) {
        if (prime(i)) {
            cout << i << endl;
        }
    }
    
    return 0;
}
