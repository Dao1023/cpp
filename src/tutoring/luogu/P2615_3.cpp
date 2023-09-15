#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 0;
        }
    }
    int row, col;

    for (int k = 1; k <= n*n; k++) {
        if (k == 1) {
            row = 1;
            col = (n+1)/2;
        } else if (row == 1 && col != n) {
            row = n;
            col++;
        } else if (row != 1 && col == n) {
            row--;
            col = 1;
        } else if (row == 1 && col == n) {
            row++;
        } else if (row != 1 && col != n) {
            if (a[row-1-1][col+1-1] == 0) {
                row--;
                col++;
            } else {
                row++;
            }
        }
        a[row-1][col-1] = k;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}