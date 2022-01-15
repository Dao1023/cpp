#include <bits\stdc++.h>
#define maxsize 10

typedef int type;
typedef struct
{
    type *data;
    type top;
} Stack;

Stack initStack()
{
    Stack s;
    s.data = (type *)malloc(sizeof(type) * maxsize);
    s.top = 0;
    return s;
}

int push(Stack *s, type elem)
{
    if (s->top == maxsize)
    {
        return 0;
    }
    s->data[s->top] = elem;
    s->top++;
    return 1;
}

int pop(Stack *s)
{
    if (s->top == 0)
    {
        return 0;
    }
    s->top--;
    return 1;
}

int size(Stack *s)
{
    return s->top;
}

int isempty(Stack *s)
{
    if (s->top == 0)
    {
        return 1;
    }
    return 0;
}

int top(Stack *s)
{
    if (s->top == 0)
    {
        return 0;
    }
    return s->data[s->top - 1];
}


void del(Stack *s)
{
    free(s->data);
}

int main()
{
    Stack ops = initStack();
    Stack nms = initStack();
    char ch[100];
    scanf("%s", ch);
    int i = 0;
    char tc;
    int lx = 0;
    int number;
    int tnum, nextnum;
    while (1)
    {
        tc = ch[i];
        if (tc != '\0')
        {
            if (tc <= '9' && tc >= '0')
            {
                if (lx == 1)
                {
                    number = top(&nms);
                    pop(&nms);
                    push(&nms, number * 10 + (int)(tc - '0'));
                }
                else
                {
                    lx = 1;
                    push(&nms, (int)(tc - '0'));
                }
                i++;
            }
            else if (tc == '+' || tc == '-')
            {
                push(&ops, (int)tc);
                lx = 0;
                i++;
            }
            else if (tc == '*')
            {
                tnum = top(&nms);
                pop(&nms);
                nextnum = 0;
                while (1)
                {
                    i++;
                    if (ch[i] <= '9' && ch[i] >= '0')
                    {
                        nextnum = nextnum * 10 + (int)(ch[i] - '0');
                    }
                    else
                    {
                        break;
                    }
                }
                push(&nms, tnum * nextnum);
                lx = 0;
            }
            else if (tc == '/')
            {
                tnum = top(&nms);
                pop(&nms);
                nextnum = 0;
                while (1)
                {
                    i++;
                    if (ch[i] <= '9' && ch[i] >= '0')
                    {
                        nextnum = nextnum * 10 + (int)(ch[i] - '0');
                    }
                    else
                    {
                        break;
                    }
                }
                push(&nms, tnum / nextnum);
                lx = 0;
            }
            else if (tc == '=')
            {
                int n1, n2;
                while (!isempty(&ops))
                {
                    tc = (char)top(&ops);
                    pop(&ops);
                    n1 = top(&nms);
                    pop(&nms);
                    n2 = top(&nms);
                    pop(&nms);
                    if (tc == '+')
                    {
                        push(&nms, n2 + n1);
                    }
                    else
                    {
                        push(&nms, n2 - n1);
                    }
                }
                break;
            }
        }
        else
        {
            break;
        }
    }
    int ans = top(&nms);
    printf("%d\n", ans);
    return 0;
}
