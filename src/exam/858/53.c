#include <stdio.h>

typedef struct {
	int id;
	int score;
} S;

void function(S s[], int n) {

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