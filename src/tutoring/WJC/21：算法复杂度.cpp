#include <iostream>

using namespace std;

int main () {
	int n = 7;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << count++ << " ";
		}
		cout << endl;
	}
	return 0;
} 
