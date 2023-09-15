#include <iostream>
using namespace std;

// 山形数判断：十位大于百位和个位的三位数
int function(int number) {
    if (number < 100 || number > 999) {
        return 0;
    }
    int a = number / 100;
    int b = number / 10 % 10;
    int c = number % 10;

    if (a > b || a < c) {
        
    }
    return 0;
}

int main() {

    
    return 0;
}
