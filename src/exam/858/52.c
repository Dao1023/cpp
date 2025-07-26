#include <stdio.h>

typedef struct {
	int id;
	int score;
} S;

void function(S s[], int n) {
	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if (s[min].score > s[j].score) min = j;
		}
		S temp = s[min];
		s[min] = s[i];
		s[i] = temp;
	}
}

int main() {
	S s[4];
	s[0].id = 1;
	s[0].score = 60;
	s[1].id = 2;
	s[1].score = 90;

	function(s, 2);

	for (int i = 0; i < 2; i++) {
		printf("%d, ", s[i].score);
	}
}