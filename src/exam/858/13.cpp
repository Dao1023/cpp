#include <stdio.h>
#include <math.h>



int main() {
	int a[100];
	int k = 0;
    for (int i = 1; i <= 100; i++) {
    	if ((i % 7 == 0 || i % 11 == 0) && (i % 77 != 0)) {
    		a[k++] = i;
		}
	}
	
	printf("�������������� %d ��:\n", k);
    for (int i = 0; i < k; i++) {
        printf("%d ", a[i]); // ���������������
    }
    
    return 0;
}

