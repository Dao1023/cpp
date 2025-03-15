#include <stdio.h>
#include <math.h>


// 九进制转十进制 
int nine2ten(int n) {
	int sum = 0;
	int count = 0;
	
	while (n > 0) {
		sum += (n % 10) * pow(9, count++);
		n /= 10;
	}
	
	return sum;
}


int main() {
	
	int n = 110;
	n = nine2ten(n);
	printf("%d", n);
	
	return 0;
}
