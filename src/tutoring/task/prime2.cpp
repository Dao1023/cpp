#include <iostream>
using namespace std;

int prime(int number) {
    for (int i=2; i<number; i++) {
        if (number%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    for (int i=2; i<=100; i++) {
        if (prime(i)) {
            cout << i << " ";
        }
    };
    return 0;
}
