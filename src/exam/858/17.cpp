#include <stdio.h>
#include <math.h>



int function(int *s, int t, int *k) {
	int max = 0;
	
	for (int i = 0; i < t; i++) {
		if (s[i] > s[max]) max = i;
	}
	*k = max;
	
	return 0;
}

int main() {
	int s[] = {1, 3, 4, 2};
    int len = sizeof(s) / sizeof(s[0]);
    int k;
    
    int result = function(s, len, &k);
    printf("���Ԫ��������%d\n", k);
    printf("���Ԫ�ص�ֵ��: %d", s[k]);
    
    return 0;
}

