#include <iostream>

using namespace std;

int main() {
	double s = 0.0, a;
	
	for (int i = 1; i <= 50; i++) {
		
		a = 0.0;
		for (int j = 1; j <= i; j++) {
			a += j;
		}
		
		s += 1.0 / a;	
	}
	cout << s;
	
	return 0;
}
