#include "bits/stdc++.h"
using namespace std;
#pragma once
#ifndef _DEFINE_H
#define _DEFINE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define Empty -1
#define MaxSize 50 //可输入50个字符

typedef struct StackRecord
{ //
	int Capacity;
	int TopofStack;
	char *array;
} * Stack;
typedef struct StackRecord1
{
	int Capacity;
	int TopofStack;
	double *array;
} * Stack1;
///对栈的操作
int IsEmpty(Stack S);				 //判断栈是否为空
int IsFull(Stack S);				 //判断栈是否已满
Stack CreateStack(int CHARDigits);	 //字符栈的创建
Stack1 CreateStack1(int CHARDigits); //
void DisposeStack(Stack S);			 //释放栈
int MakeEmpty(Stack S);				 //置空栈
int MakeEmpty1(Stack1 S);
void Push(Stack S, char x);
int Top(Stack S, char *element);
void Pop(Stack S, char *element); //置空栈
#endif
//初始化
int MakeEmpty(Stack S)
{ //初始化栈
	return S->TopofStack = Empty;
}
int MakeEmpty1(Stack1 S)
{ //初始化栈
	return S->TopofStack = Empty;
}
int IsEmpty(Stack S)
{ //判空
	return S->TopofStack == Empty;
}
int IsFull(Stack S)
{ //判满
	return S->TopofStack == S->Capacity;
}
//分配空间，创建字符串栈
Stack CreateStack(int CHARDigits)
{
	Stack S;
	S = (Stack)malloc(sizeof(struct StackRecord));
	if (S == NULL)
	{
		printf("out of space");
		return 0;
	}
	S->array = (char *)malloc(sizeof(int) * CHARDigits);
	if (S->array == NULL)
	{
		printf("out of space");
		return 0;
	}
	S->Capacity = CHARDigits;
	MakeEmpty(S);
	return S;
}
//存放double的栈
Stack1 CreateStack1(int CHARDigits)
{
	Stack1 S;
	S = (Stack1)malloc(sizeof(struct StackRecord));
	if (S == NULL)
	{
		printf("out of space");
		return 0;
	}
	S->array = (double *)malloc(sizeof(int) * CHARDigits);
	if (S->array == NULL)
	{
		printf("out of space");
		return 0;
	}
	S->Capacity = CHARDigits;
	MakeEmpty1(S);
	return S;
}
//入栈
void Push(Stack S, char x)
{
	if (IsFull(S))
	{
		printf("stack is full");
	}
	else
		S->array[++S->TopofStack] = x;
}
//出栈
void Pop(Stack S, char *element)
{
	if (IsEmpty(S))
		printf("stack is empty");
	else
		*element = S->array[S->TopofStack--];
}
//栈顶元素
int Top(Stack S, char *element)
{
	if (!IsEmpty(S))
	{
		*element = S->array[S->TopofStack];
		return 1;
	}
	else
	{
		printf("empty stack\t");
		return 0;
	}
}
//中缀转后缀
void TransLate(Stack S, char a[], char b[])
{
	char ch, element = NULL;
	int i = 0, j = 0;
	ch = a[i++];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(': //左括号出现，右括号不出现就有符号入栈
			Push(S, ch);
			break;
		case ')': //右括号出现，括号里面的所有符号出栈
			while (Top(S, &element) && element != '(')
			{
				Pop(S, &element);
				b[j++] = element;
			}
			Pop(S, &element); //将左括号出栈
			break;
		case '+':
		case '-': //加减的优先级最低压入栈底
			while (!IsEmpty(S) && Top(S, &element) && element != '(')
			{
				Pop(S, &element);
				b[j++] = element;
			}
			Push(S, ch);
			break;
		case '*':
		case '/': //乘除优先级比加减高遇到加减入栈,其他情况元素出栈再入栈
			while (!IsEmpty(S) && Top(S, &element) && element == '/' || element == '*' || element == '^')
			{
				Pop(S, &element);
				b[j++] = element;
			}
			Push(S, ch);
			break;
		case '^': //次幂优先级大于乘除，遇到'^'出栈再入栈，其他情况入栈
			while (!IsEmpty(S) && Top(S, &element) && element == '^')
			{
				Pop(S, &element);
				b[j++] = element;
			}
			Push(S, ch);
			break;
		case ' ':
			break;
		default: //数字的字符串优先级最低，不入栈直接输出
			while (ch >= '0' && ch <= '9')
			{
				b[j++] = ch;
				ch = a[i++];
			}
			i--;
			b[j++] = ' ';
		}
		ch = a[i++];
	}
	while (!IsEmpty(S)) //剩余字符输出
	{
		Pop(S, &element);
		b[j++] = element;
	}
	b[j] = '\0';
}
//对后缀表达式进行计算
double Caluate(Stack1 S, char b[])
{
	int i = 0;
	int value;
	double x1, x2, result;
	while (b[i] != '\0')
	{
		if (b[i] != ' ' && b[i] >= '0' && b[i] <= '9')
		{
			value = 0;
			while (b[i] != ' ')
			{
				value = 10 * value + b[i] - '0'; //整数转换，将字符转换为整型
				i++;
			}
			S->array[++S->TopofStack] = value; //整数入栈
		}
		else
		{ //遇见符号出栈两个数进行操作符运算
			switch (b[i])
			{
			case '+':
				x1 = S->array[S->TopofStack--];
				x2 = S->array[S->TopofStack--];
				result = x1 + x2;
				S->array[++S->TopofStack] = result;
				break;
			case '-':
				x1 = S->array[S->TopofStack--];
				x2 = S->array[S->TopofStack--];
				result = x2 - x1;
				S->array[++S->TopofStack] = result;
				break;
			case '*':
				x1 = S->array[S->TopofStack--];
				x2 = S->array[S->TopofStack--];
				result = x1 * x2;
				S->array[++S->TopofStack] = result;
				break;
			case '/':
				x1 = S->array[S->TopofStack--];
				x2 = S->array[S->TopofStack--];
				result = x2 / x1;
				S->array[++S->TopofStack] = result;
				break;
			case '^':
				x1 = S->array[S->TopofStack--];
				x2 = S->array[S->TopofStack--];
				result = pow(x2, x1);
				S->array[++S->TopofStack] = result;
				break;
			}
			i++;
		}
	}
	if (S->TopofStack != -1)
	{ //返回结果
		result = S->array[S->TopofStack--];
		if (S->TopofStack == -1)
			return result;
		else
		{
			printf("表达式错误");
			exit(-1);
		}
	}
}
int main()
{
	Stack S1;
	Stack1 S2;
	char a[MaxSize], b[MaxSize];
	int num;
	double result;
	printf("输入算术表达式:");
	gets(a);
	printf("infix is :%s\n", a); //输出中缀
	num = strlen(a);
	S1 = CreateStack(num); //根据字符串的长度分配栈的大小
	S2 = CreateStack1(num);
	TransLate(S1, a, b);
	printf("postfix is :%s\n", b); //输出后缀
	result = Caluate(S2, b);
	printf("%f", result);
	return 0;
}
