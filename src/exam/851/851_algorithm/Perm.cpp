#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// list[k:m] 的排列
// list[0] 为占位符
void Perm(int list[], int k, int m) {
    if (k == m) {
        for (int i = 1; i <= m; i++) {
            cout << list[i];
        }
        cout << endl;
    } else {
        for (int i = k; i <= m; i++) {
            cout << "k: " << k << " m: " << m << " list: ";
            swap(list[k], list[i]);
            Perm(list, k+1, m);
            swap(list[k], list[i]);
        }
    }
}

int main() {
    int a[4] = {0, 1, 2, 3};
    Perm(a, 1, 3);
}