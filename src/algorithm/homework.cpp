#include <iostream>
using namespace std;

struct Homework {
    int no; //作业的序号
    int deadline; //作业的截止日期
    int deduction; //逾期的扣分
};

void sort(Homework homework [], int n) //使用直接选择排序对作业按紧急程度排序
{
    int most_emergent; //表示最紧急的作业的序号
    Homework tmp;
    for ( int i = 0; i < n - 1; i++) {
        most_emergent = i;
        for ( int j = i + 1; j < n; j++) {
            if (homework [j].deadline < homework [most_emergent].deadline) //截止时间越近的作业越紧急
                most_emergent = j;
            else if (homework [j].deadline == homework [most_emergent].deadline && homework [j].deduction > homework [most_emergent].deduction) //截止时间相同时，扣分越多的作业越紧急
                most_emergent = j;
        }
        tmp = homework [i];
        homework [i] = homework [most_emergent];
        homework [most_emergent] = tmp;
    }
}

int main(void)
{
    int n, time, deducted_point;
    cin >> n;
    while (n != 0) {
        Homework* homework = new Homework [n];
        for ( int i = 0; i < n; i++) {
            homework [i].no = i + 1;
            cin >> homework [i].deadline;
        }
        for ( int i = 0; i < n; i++)
            cin >> homework [i].deduction;
        sort (homework, n);
        time = 1; //表示当前是第几天
        deducted_point = 0; //目前已扣分数
        for ( int i = 0; i < n; i++) {
            if (time <= homework [i].deadline) //如果当前时间没超过homework [i]的截止时间，则做这个作业
            {
                cout << homework [i].no << ' ';
                time++;
            }
            else //否则就扣分
                deducted_point += homework [i].deduction;
        }
        cout << endl;
        cout << deducted_point << endl;
        delete [] homework;
        cin >> n;
    }
    return 0;
}
