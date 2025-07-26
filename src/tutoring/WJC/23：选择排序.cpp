#include <iostream>

using namespace std;

int main() {
	int n = 10;
	int a[n] = {0, 4, 2, 1, 9, 5, 8, 7, 3, 6};
	
	for (int i = 0; i < n-1; i++) {
		int min = i;
		
		for (int j = i; j < n; j++) {
			if (a[j] < a[min]) { min = j; }
		}
		
		swap(a[i], a[min]);
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i];
	}
	
	return 0;
} 
