#include <iostream>
#include <string>
using namespace std;

int main() {

    // 不需要分号
    #define MAX 255

    typedef unsigned int COUNT;
    
    typedef struct student {
        string name;
        int num;
        float score;
    } Student;

    Student s1, s2;
    s1.name = "LiHua";
    s1.num = 005;
    s1.score = 97.5;

    // 声明并分别存数
    int a[3];
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    // 初始化全部数值
    int b[3] = {1, 2, 3};
    // 初始化部分数值，其他部分为 0
    int c[3] = {1, 2};

    // * 是取值
    // & 是取地址
    int *p;
    int s = 3;
    p = &s;
    
    // 也可以 debug 查看
    int *p1 = a;
    printf("*p1 = %d\n", *p1);
    printf("&p1 = %p\n", &p1);

    // 链表
    typedef int ElemType;
    typedef struct LNode {
        ElemType data;
        struct LNode *next;
    } LNode, *LinkList;

    // 函数声明
    int max(int a, int b);

    // 函数实现
    int max(int a, int b) {
        return a > b ? a : b; // 三元运算符结构：<条件 ? 真值 : 假值>
    }

    return 0;
}
