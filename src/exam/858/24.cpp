#include <stdio.h> 
#include <math.h>


unsigned function(unsigned w) {
	unsigned v = w;
	int count = 0;
	
	while (w > 10) {
		w /= 10;
		count++; 
	}
	return v - w * pow(10, count);
}

int main() {
	
	printf("%d", function(12345));
	
	return 0;
}
