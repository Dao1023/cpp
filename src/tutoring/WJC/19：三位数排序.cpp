#include <iostream>

using namespace std;

int main () {
	int a, b, c;
	cin >> a >> b >> c;
	
	if (a < b) {
		if (c < a) { cout << c << " " << a << " " << b; }
		else if (c > b) { cout << a << " " << b << " " << c; }
		else { cout << a << " " << c << " " << b; }
	} else {
		if (c < b) { cout << c << " " << b << " " << a; }
		else if (c > a) { cout << b << " " << a << " " << c; }
		else { cout << b << " " << c << " " << a; }
	}
	
	return 0;
} 
