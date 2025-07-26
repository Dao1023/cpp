#include <stdio.h>
#include <math.h>

#define N 100

/*
double func(double score[N], int n) {
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		sum += score[i];
	}
	double ave = sum / n;
	
	double below[n];
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (score[i] < ave) below[k++] = score[i];
	}
	return k;
}

int main() {
	double score[N] = {1, 2, 3, 4};
	printf("%lf", func(score[N], 4));
	
	return 0;
}
*/


int function(int score[], int m, int below[]) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += score[i]; // �����ܷ�
    }
    double average = (double)sum / m; // ����ƽ����

    int count = 0; // ����ƽ���ֵ�����
    for (int i = 0; i < m; i++) {
        if (score[i] < average) {
            below[count++] = score[i]; // ������ƽ���ֵķ������� below ����
        }
    }
    return count; // ���ص���ƽ���ֵ�����
}

int main() {
    int score[] = {85, 72, 90, 60, 78, 95, 88};
    int m = sizeof(score) / sizeof(score[0]); // �������鳤��
    int below[m]; // ���ڴ洢����ƽ���ֵķ���

    int count = function(score, m, below); // ���ú���

    printf("����ƽ���ֵ�����: %d\n", count);
    printf("����ƽ���ֵķ���: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", below[i]); // �������ƽ���ֵķ���
    }
    printf("\n");

    return 0;
}

