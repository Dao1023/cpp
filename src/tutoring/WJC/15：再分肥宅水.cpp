#include <iostream>

using namespace std;

int main() {
	double t;
	int n;
	
	cin >> t >> n;
	
	// printf("123\n");
	printf("%.3lf\n", t/n);
	printf("%d", n*2);
	printf("%.3lf\n%d", t/n, n*2);

	cout << 2*n;
	
	return 0;
} 
