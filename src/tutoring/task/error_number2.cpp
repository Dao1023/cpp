/*
ab*cde = adb*ce
123*45 = 13*425

01
001
0001
00001


1234

1234/1000 = 1
1%10 = 1

1234/100 = 12
12 % 10 = 2

1234/10 = 123
123%10 = 3

1234/1 = 1234
1234%10=4
*/

#include <iostream>
using namespace std;

int main() {
    int s = 0;

    for (int i=10; i <= 99; i++) {
        for (int j=100; j <= 999; j++) {
            
            // ab*cde = adb*ce
            int a = i/10;
            int b = i%10;
            int c = j/100;
            int d = j/10%10;
            int e = j%10;
            
            // x=ab*cde，y=adb*ce
            int x = (a*10+b) * (c*100+d*10+e);
            int y = (a*100+d*10+b) * (c*10+e);
            if (x==y) {
                cout << a*10+b << "*" << c*100+d*10+e << " = ";
                cout << a*100+d*10+b << "*" << c*10+e << " = ";
                cout << x << endl;
                s++;
            }
        }
    }

    cout << s << endl;
    return 0;
}
