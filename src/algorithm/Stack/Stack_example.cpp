#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 5
#include <stdio.h>

typedef struct //堆栈结构体定义
{
    int top;           //栈顶指针
    int data[MaxSize]; //静态数组存放栈中元素
} SqStack;

void InitStack(SqStack &S) //初始化栈
{
    S.top = -1; //初始化栈顶指针
}

int testStack(SqStack &S) //判断栈空
{                         //只需要判断栈顶指针指向的是不是-1，因为一开始空栈的时候栈顶指针指向的是-1。
    return (S.top == -1); //空栈返回1，反之返回0。
}

int IsFull(SqStack &S) //判断栈满
{
    return (S.top == MaxSize - 1); //满栈返回1，反之返回0。
}

bool Push(SqStack &S) //入栈（在栈顶位置插入元素）
{
    printf("请输入%d个数:", MaxSize);
    for (int i = 0; i < MaxSize; i++)
    {
        if (S.top == MaxSize - 1) //判断栈满了没有
            return false;
        S.top = S.top + 1;           //栈顶指针往上一位
        scanf("%d", &S.data[S.top]); //把这次输入的元素放入此时栈顶指针指向的位置
    }
    return true;
}

bool GetTop(SqStack &S) //读取栈顶元素，操作和出栈类似，top不需要减1。
{
    if (S.top == -1)
        return false;
    int x = S.data[S.top];
    printf("栈顶元素是：%d\n", x);
    return true;
}

int lenth(SqStack &S) //求有效元素的个数
{
    return S.top + 1;
}

bool Printf(SqStack &S, int &x) //出栈(删除栈顶元素)
{
    if (S.top == -1) //判断是否为空栈
        return false;
    x = S.data[S.top]; //让x等于此时栈顶指针所指的元素
    S.top = S.top - 1; //栈顶指针往下移动一位
    return true;
}

void DestroyStack(SqStack &S) //销毁栈
{
    char a;
    getchar();
    printf("是否销毁顺序栈(Y/N):");
    scanf("%c", &a);
    if (a == 'Y')
    {
        printf("销毁成功\n");
        S.top = -1;
    }
    else
        printf("未销毁\n");
}

int main()
{
    int x;
    SqStack S;            //声明栈
    InitStack(S);         //初始化栈
    Push(S);              //入栈
    int a = testStack(S); //判断栈空
    a == 1 ? printf("栈空\n") : printf("栈不是空的\n");
    a = IsFull(S);
    a == 1 ? printf("栈满\n") : printf("栈不满\n");
    GetTop(S); //读取栈顶元素
    int len = lenth(S);
    printf("栈内元素个数：%d\n", len);
    Printf(S, x);    //出栈
    DestroyStack(S); //销毁栈
    return 0;
}
