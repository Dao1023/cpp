#include <stdio.h>
#include <math.h>


// 将两个两位数的正整数a b合并形成一个整数放在c中。合并的方式是：将a数的十位和个位数依次放在c的十位和千位上，b数的十位和个位数依次放在c数的个位和百位上。
int main() {
	int a = 12;
	int b = 34;
	int c = 0;
	
	c += a % 10 * 10;
	c += a / 10 * 1000;
	c += b / 10;
	c += b % 10 * 100;
	
	printf("%d", c);
	
	return 0;
}
