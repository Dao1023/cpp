#include <iostream>

using namespace std;

int main () {
	// 一起输入 
	int n = 10;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	// 选择排序
	// 原理：遍历一遍，每次把最小 min 的移动到 i
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min]) { min = j; }
		}
		if (min != i) { swap(a[min], a[i]); }
	}
	
	// 一起输出 
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	return 0;
} 
