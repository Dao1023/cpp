#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef struct
{
    int *top;
    int *base;
    int stacksize;
} sqstack;

int initstack(sqstack &s)
{
    s.base = new int[100];
    if (!s.base)
        exit(OVERFLOW);
    s.top = s.base;
    s.stacksize = 100;
    return 1;
}

int push(sqstack &s, int e)
{
    if (s.top - s.base == s.stacksize)
        return -1;
    *s.top = e;
    s.top++;
    return 1;
}

int pop(sqstack &s, int &e)
{ //出栈
    if (s.top == s.base)
        return -1;
    s.top--;
    e = *s.top;
    return 1;
}

int main()
{
    sqstack Stack;
    initstack(Stack);
    
    // 获取数量
    int n;
    cin >> n;
    
    // 入栈
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        push(Stack, input);
    }
    // 出栈
    for (int i = 0; i < n; i++)
    {
        int input;
        pop(Stack, input);
        cout << input << " ";
    }
    return 1;
}
