#include <stdio.h> 
#include <math.h>


float function(double h) {
	int i = (int) h;
	double f = h - i;
	
	int f_1, f_2, f_3;
	f *= 10; f_1 = (int) f; f -= f_1;
	f *= 10; f_2 = (int) f; f -= f_2;
	f *= 10; f_3 = (int) f;
	if (f >= 5) f_2 += 1;
	
	return i + (float)f_1 / 10 + (float)f_2 / 100;
	
}

int main() {
	
	printf("%f", function(123.4567));
	// ��� 123.459999 
	// ����취���� round��printf ֱ����������
	// �Լ�����ֵʵ�ַǳ����� 
	// �����������ַ����������� 
	
	return 0;
}
