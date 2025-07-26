#include <stdio.h>
#include <stdlib.h>
#define ElemType char
#define MAX_SIZE 100

typedef struct BTNode
{
    ElemType data;         //结点数据
    struct BTNode *Lchild; //左子结点指针
    struct BTNode *Rchild; //右子结点指针
} BTNode, *BinTree;

BTNode *Create_BTree(BinTree &T) //建立链式二叉树，返回指向根结点的指针变量
{
    ElemType ch;
    ch = getchar();
    getchar();
    if (ch == '?')
    {
        T = NULL;
        return (T);
    }
    else
    {
        T = (BTNode *)malloc(sizeof(BTNode));
        T->data = ch;
        Create_BTree(T->Lchild);
        Create_BTree(T->Rchild);
        return (T);
    }
}

void PreOrder_Traverse(BinTree t) //先序非递归遍历算法
{
    BinTree st[MAX_SIZE]; //声明一个栈数组，用于实现LIFO结点调用
    int top = -1;
    while (t || top != -1)
    {
        while (t) //一路向左
        {
            printf("%c", t->data);
            st[++top] = t; //入栈
            t = t->Lchild;
        }
        if (top != -1) //取出一个右结点
        {
            t = st[top--]; // top--是为了查询最左结点的右结点,而不是--top
            t = t->Rchild;
        }
    }
}

void InOrder_Traverse(BinTree t) //中序非递归遍历算法
{
    BinTree st[MAX_SIZE]; //声明一个栈数组，用于实现LIFO结点调用
    int top = -1;
    while (t || top != -1)
    {
        while (t) //一路向左
        {
            st[++top] = t; //入栈
            t = t->Lchild;
        }
        if (top != -1) //取出一个右结点
        {

            t = st[top--]; // top--是为了查询最左结点的右结点
            printf("%c", t->data);
            t = t->Rchild;
        }
    }
}

//先序：DLR，后序：LRD
//左右结点颠倒的先序遍历:DRL
// DRL进行一个颠倒(即一轮入栈和出栈)即为LRD，从而实现后序非递归遍历算法
void PostOrder_Traverse(BinTree t) //先序非递归遍历算法
{
    BinTree st[MAX_SIZE]; //声明一个栈数组，用于实现LIFO结点调用
    int top = -1;
    ElemType s[MAX_SIZE]; //建立顺序栈，进行压栈与出栈行为
    int top1 = 0;
    while (t || top != -1)
    {
        while (t) //一路向左
        {
            s[top1++] = t->data; //先序时为（printf("%c",t->data);）,这里将其进行压栈
            st[++top] = t;       //入栈
            t = t->Rchild;       //先序时为（t=t->Lchild;）,这里进行左右结点颠倒
        }
        if (top != -1) //取出一个右结点
        {
            t = st[top--]; // top--是为了查询最左结点的右结点
            t = t->Lchild; //先序时为（t=t->Rchild;）,这里进行左右结点颠倒
        }
    }
    while (top1--)
        printf("%c", s[top1]); //进行出栈，完成颠倒
}

void Find_path(BinTree t, ElemType c) //求指定结点路径
{
    static ElemType path[MAX_SIZE];
    static int i = 0;
    if (!t)
        return;       //当前访问的结点为空，直接返回
    if (t->data == c) //已找到目标
    {
        printf("路径为：");
        for (int j = 0; j < i; j++)
            printf("%c->", path[j]); //输出目标结点的祖先
        printf("%c\n", t->data);     //输出目标结点
        return;
    }
    else
    {
        path[i++] = t->data;
        Find_path(t->Lchild, c);
        Find_path(t->Rchild, c); //利用先序遍历算法来查找路径，从根结点开始查，仅查祖先
        i--;
    }
}

int main()
{
    BinTree t = NULL; //根节点指针
    ElemType ch;
    printf("按照先序遍历输入二叉树：");
    t = Create_BTree(t);

    printf("先序遍历输出：");
    PreOrder_Traverse(t);
    printf("\n");
    printf("中序遍历输出：");
    InOrder_Traverse(t);
    printf("\n");
    printf("后序遍历输出：");
    PostOrder_Traverse(t);
    printf("\n");

    while (1)
    {
        printf("输入要查询路径的结点：");
        scanf("%c", &ch);
        getchar();
        Find_path(t, ch);
        printf("\n");
    }
    return 0;
}
