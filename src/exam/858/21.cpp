#include <stdio.h>
#include <math.h>


/*
1 2 3
4 5 6
7 8 9

0 2 3
0 0 6
0 0 0
*/

// ʹ�������°�����Ԫ���е�ֵȫ���ó� 0
// �����Խ��� 
void function(int a[][3], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			a[i][j] = 0;
		}
	}
}

int main() {
	int a[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	function(a, 3);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	
    return 0;
}
 
