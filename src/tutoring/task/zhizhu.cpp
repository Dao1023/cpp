#include <iostream>
using namespace std;

int zhishu(int number) {
    for (int i=2; i<=number-1; i++) {
        if (number%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    cout << "2: " << zhishu(2) << endl;
    cout << "3: " << zhishu(3) << endl;
    cout << "4: " << zhishu(4) << endl;
}