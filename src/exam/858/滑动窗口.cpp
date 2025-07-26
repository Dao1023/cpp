
// {1, 2, 3, 4, 1}
// ��ĳ��һά���飬Ѱ�������� k �����֣�ʹ֮���
// �������ڣ�O(n) 

#include <stdio.h> 


// V0.1������ 
int main() {
	int a[] = {1, 2, 3, 4, 1};
	int k = 3;
	
	int len = sizeof(a) / sizeof(a[0]);
	int max = 0, windows, index, j;
	for (int i = 0; i < len - k; i++) {
		windows = 0;
		for (j = i; j < i + k; j++) windows += a[j];
		if (max < windows) {	
			max = windows;
			index = --j;
		}
	}	
	
	for (int i = index; i > index - k; i--) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("max = %d", max);

	return 0;
}

/*
// V0.2���Ѳ����ظ�������ߵ� 
int main() {
	int a[] = {1, 2, 3, 4, 1};
	int k = 3;
	
	int len = sizeof(a) / sizeof(a[0]);
	int max = 0, windows, index, j;
	for (int i = 0; i < len - k; i++) {
		windows = 0;
		
		for (j = i; j < i + k; j++) {
			if (����ͷ��һ����β��С) continue;
			windows += a[j];
		}
		if (max < windows) {	
			max = windows;
			index = --j;
		}
	}	
	
	for (int i = index; i > index - k; i--) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("max = %d", max);

	return 0;
}
*/


