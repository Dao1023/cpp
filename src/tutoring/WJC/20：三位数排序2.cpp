#include <iostream>

using namespace std;

int main () {
	// һ������ 
	int n = 10;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// ѡ������
	// ԭ������һ�飬ÿ�ΰ���С min ���ƶ��� i
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min]) { min = j; }
		}
		if (min != i) { swap(a[min], a[i]); }
	}
	
	// һ����� 
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	return 0;
} 
