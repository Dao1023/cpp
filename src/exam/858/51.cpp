#include <stdio.h>

struct Student {
	int id;
	int score;
};

void function(Student a[], int n, Student *s) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[max].score < a[i].score) max = i;
	}
	*s = a[max];
}

int main() {
	Student a[2];
	a[0].id = 1;
	a[0].score = 60;
	a[1].id = 2;
	a[1].score = 90;	
	
	Student s;
	
	function(a, 2, &s);
	
	for (int i = 0; i < 2; i++) {
		printf("%d, ", a[i].score);
	}
}
