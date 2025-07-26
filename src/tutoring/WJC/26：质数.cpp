#include <iostream>

using namespace std;

int main() {
	int n = 8;
	int q = 1;
	
	for (int i = 2; i < n; i++) {
		if (n % i == 0) { q = 0; }
	} 
	
	if (q == 0) { cout << "no"; }
	else { cout << "yes"; }
	
	return 0;
}
