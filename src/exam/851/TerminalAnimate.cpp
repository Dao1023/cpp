#include <math.h>
#include <iostream>
using namespace std;

// 图像矩阵
template<int n>
void matrixInit(char &array[n][n]) {
    for (int i; i < n; i++) {
        for (int j; j < n; j++) {
            array[i][j] = (char) 0;
        }
    }
}

// 邻域，n 是邻域半径
// PS：代码是有问题的，因为 C++ 不能返回数组类型
// int deltaArray(int x, int n) {
//     int array[2 * n + 1];
//     for (int i = 0; i < n; i++) {
//         array[n] = x;
//         array[n - i] = x - i;
//         array[n + i] = x + i;
//     }
//     return array;
// }

template<int n>
void circle(char &array[n][n], int r) {
    int MaxWeigth = r * 2 + 1;
    int MaxHeigth = r * 2 + 1;
    int x_0 = r;        // 圆心 x
    int y_0 = r;        // 圆心 y
    int delta = r / 2;  // 容错范围
    for (int y = 0; y < MaxHeigth; y++) {
        for (int x = 0; x < MaxWeigth; x++) {
            array[y][x] = " ";
            if (pow((x - x_0), 2) + pow((y - y_0), 2) < pow(r, 2) + delta &&
                pow((x - x_0), 2) + pow((y - y_0), 2) > pow(r, 2) - delta) {
                array[y][x] = "*";
            } else {
                array[y][x] = " ";
            }
        }
        cout << endl;
    }
}

// 渲染函数
template<int n>
void render(char &array[n][n]) {
    for (int i; i < n; i++) {
        for (int j; j < n; j++) {
            cout << array[i][j];
        }
    }
}

int main() {
    int n = 30 * 2 + 1;
    char array[n][n];
    matrixInit(array);
    circle(array, (n-1)/2);
    render(array);
}