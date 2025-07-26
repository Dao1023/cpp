#include <iostream>
#include <math.h>
using namespace std;

#define PI acos(-1)

double yuanhuan(int small, int big) {
    double S_big = big * big * PI;
    double S_small = small * small * PI;
    double S_0 = S_big - S_small;
    return S_0;
}

int main() {
    cout << "面积 = " << yuanhuan(2,4) << endl;
    cout << "面积 = " << yuanhuan(5, 7) << endl;
    cout << "面积 = " << yuanhuan(10, 15) << endl;
    cout << "面积 = " << yuanhuan(20, 25) << endl;
}