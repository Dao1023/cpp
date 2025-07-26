#include <iostream>
using namespace std;

int main() {
    int num = 6;

    int ji = 0;
    int ou = 0;

    for (int i = 1; i <= num; i++) {
        if (i % 2 == 0) {
            ou += i;
        } else {
            ji += i;
        }
    }

    cout << "ji = " << ji << endl;
    cout << "ou = " << ou << endl;
    return 0;
}

