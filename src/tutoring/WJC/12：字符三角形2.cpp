#include <iostream>
using namespace std;

int main() {
	char a;
	cin >> a;
	
	int rows = 3;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) {
            cout << a;
        }
        cout << endl;
    }

    return 0;
}
