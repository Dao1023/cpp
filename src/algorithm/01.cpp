/*
[问题描述]小v. 上学,老师布置了n个作业,每个作业恰好需要一天做完,每个作业都有最后提交时间及其逾期的扣分。请给出小v做作业的顺序,以便扣最少的分数。输人描述:输人包含多个测试用例。每个测试用例的第1行为整数n(1≤n≤100),表示作业数,第2行包括n个整数，表示每个作业最后提交的时间(天),第3行包括n个整数，表示每个作业逾期的扣分。以输人n=0结束。输出描述:每个测试用例对应两行输出,第1行为做作业的顺序(作业编号之间用空格分隔),第2行为最少的扣3分。

输入样例：
3
1 3 1
6 2 3

样例输出：
1 2
3

*/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time;
    int penalty;
    int index;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;

    // 按照最后提交时间排序
    if (jobA->time != jobB->time) {
        return jobA->time - jobB->time;
    }

    // 如果最后提交时间相同，按照逾期扣分排序
    return jobA->penalty - jobB->penalty;
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        Job *jobs = (Job *)malloc(n * sizeof(Job));

        // 读取每个作业的最后提交时间
        for (int i = 0; i < n; i++) {
            scanf("%d", &(jobs[i].time));
        }

        // 读取每个作业的逾期扣分
        for (int i = 0; i < n; i++) {
            scanf("%d", &(jobs[i].penalty));
            jobs[i].index = i + 1;  // 作业编号从1开始
        }

        // 使用快速排序对作业进行排序
        qsort(jobs, n, sizeof(Job), compare);

        // 输出作业顺序和最少的扣分
        for (int i = 0; i < n; i++) {
            printf("%d ", jobs[i].index);
        }
        printf("\n");

        int min_penalty = 0;
        for (int i = 0; i < n; i++) {
            min_penalty += jobs[i].penalty;
        }
        printf("%d\n", min_penalty);

        free(jobs);
    }

    return 0;
}
