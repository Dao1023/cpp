#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;

    int shu[7];
    for (int i = 0; i < 7; i++) {
        cin >> shu[i];
    }

    int b[7][a];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < a; j++) {
            cin >> b[i][j];
        }
    }

    /*
    for(int i=0;i<7;i++){
            cout<<shu[i]<<" ";
    }
    for(int i=0;i<7;i++) {
            for(int j=0;j<a;j++){
                    cout<<b[i][j]<<" ";
            }
    }
    */

    int jiang[7] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < a; i++) {
        int s = 0;

        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                if (b[i][j] == shu[k]) {
                    s++;
                    break;
                }
                /*
                cout << "i：" << i << endl;
                cout << "j：" << j << endl;
                cout << "k：" << k << endl;
                cout << "s：" << s << endl;
                cout << endl;
                */
            }
        }

        if (s > 0) {
            jiang[7 - s]++;
        }
    }
    for (int i = 0; i < 7; i++) {
        cout << jiang[i] << " ";
    }
    return 0;
}