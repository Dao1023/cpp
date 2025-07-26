#include <stdio.h> 


// max 
void function(const int* a, const int len, int* max, int* index) {
	*index = 0;
	*max = a[0];
	for (int i = 1; i < len; i++) {
		if (a[*index] < a[i]) {
			*index = i;
			*max = a[i];
		}
	}
}


int main() {
	int a[] = {1, 0, 2, 3};
	int len = sizeof(a) / sizeof(a[0]);
	int max, index;
    function(a, len, &max, &index);
	printf("%d", index);	
	
	return 0;
}

