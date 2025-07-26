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
        sum += score[i]; // 计算总分
    }
    double average = (double)sum / m; // 计算平均分

    int count = 0; // 低于平均分的人数
    for (int i = 0; i < m; i++) {
        if (score[i] < average) {
            below[count++] = score[i]; // 将低于平均分的分数存入 below 数组
        }
    }
    return count; // 返回低于平均分的人数
}

int main() {
    int score[] = {85, 72, 90, 60, 78, 95, 88};
    int m = sizeof(score) / sizeof(score[0]); // 计算数组长度
    int below[m]; // 用于存储低于平均分的分数

    int count = function(score, m, below); // 调用函数

    printf("低于平均分的人数: %d\n", count);
    printf("低于平均分的分数: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", below[i]); // 输出低于平均分的分数
    }
    printf("\n");

    return 0;
}

