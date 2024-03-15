#include <iostream>

using namespace std;

int main() {
	
	int a[100];
	int s = 0;
	for (int i = 1; i < 100; i++) {
		s += i;
		printf("%d+", i);
	} 
	s += 100;
	printf("100 = %d", s);
	
	return 0;
}
