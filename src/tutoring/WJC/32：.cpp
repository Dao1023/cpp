#include <iostream>

using namespace std;

int add(int *a, int *b) {
	*b += 10000;
	
	return *a + *b;
}

void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c; 
}

int main() {
	int a = 1;
	int b = 2;
	
	swap(&a, &b);
	cout << a << " " << b << endl;
}
