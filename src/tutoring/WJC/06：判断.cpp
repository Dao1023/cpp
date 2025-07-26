#include <iostream>

using namespace std;

int main() {
	int a;
	cin >> a;
	
	if (a > 11) {
		cout << "Your a is bigger than 11." << endl;
	} else if (a < 10) {
		cout << "Your a is smaller than 10." << endl;
	} else if (a == 10) {
		cout << "Your a is 10." << endl;
	} else {
		cout << "Your a is 11." << endl; 
	}
	
	return 0;
}
