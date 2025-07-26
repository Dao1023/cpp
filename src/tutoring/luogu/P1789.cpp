#include <iostream>
// #include <string>
using namespace std;

#define Length 50
// int length = 30;

int main() {
    // 亮度矩阵
    int light = 0;
    int a[Length][Length];
    for (int i = 0; i < Length; i++) {
        for (int j = 0; j < Length; j++) {
            a[i][j] = light;
        }
    }

    // 放置一个火把并更新亮度
    int x = 15;
    int y = 20;
    for (int i = 0; i < Length; i++) {
        for (int j = 0; j < Length; j++) {
            light = 14 - abs(x - i) - abs(y - j);
            if (light > a[i][j]) {
                a[i][j] = light;
            }
        }
    }

    // 放置一个萤石并更新亮度
    x = 20;
    y = 10;
    for (int i = 0; i < Length; i++) {
        for (int j = 0; j <= Length; j++) {
            light = 15 - abs(x - i) - abs(y - j);
            if (light > a[i][j]) {
                a[i][j] = light;
            }
        }
    }

    // 渲染亮度
    for (int i = 0; i < Length; i++) {
        for (int j = 0; j < Length; j++) {
            light = a[i][j];
            if (light >= 10) {
                cout << light << " ";
            } else {
                cout << "0" << light << " ";
            }
        }
        cout << endl;
    }
    return 0;
}