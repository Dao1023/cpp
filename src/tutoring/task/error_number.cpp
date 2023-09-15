/*
ab*cde = adb*ce
123*45 = 13*425

01
001
0001
00001
*/

#include <iostream>
using namespace std;
int main() {
    int s = 0;

    for (int a=0; a<=9; a++) {
        for (int b=0; b<=9; b++) {
            for (int c=0; c<=9; c++) {
                for (int d=0; d<=9; d++) {
                    for (int e=0; e<=9; e++) {
                        int x = (a*100+b*10+c) * (d*10+e);
                        int y = (a*10+c) * (d*100+b*10+e);
                        if (x==y) {
                            cout << a*100+b*10+c << "*" << d*10+e << "=";
                            cout << a*10+c << "*" << d*100+b*10+e << endl;
                            s++;
                        }
                    }
                }
            }
        }
    }

    cout << s << endl;
    return 0;
}