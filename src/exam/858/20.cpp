#include <stdio.h>
#include <math.h>


int main() {
	double a = 0;
	double b = 2;
	int times = 10000000;
	double step = (b-a) / times;
	
	for (double x = a; x < b; x += step) {
		if (cos(x) - x < 0.000001) { // ¿ÉÒÔÐ´ 1e-6
			printf("root = %lf", x);
			return 0; 
		}
	}
	
    return 0;
}

