#include <iostream>
using namespace std;
const int maxsize = 100;

typedef struct BiNode
{
    char data;                      //结点数据
    struct BiNode *lchild, *rchild; //左右孩子结点指针
} * bitree;                         //定义结构体指针名为bitree

void build(bitree &t)
{
    char pch[] = "ABD@@EHJ@@KL@@M@N@@@CF@@G@I@@";
    static int i = 0; //定义静态变量i，只在第一次调用函数是赋值
    char ch = pch[i++];
    if (ch == '@')
        t = NULL;
    else
    {
        t = new BiNode;
        if (!t)
            exit(-1); // t为空，分配空间失败
        t->data = ch;

        build(t->lchild);
        build(t->rchild);
    }
}

//先序遍历非递归实现版
void PreOrderTraverse_NoRecursion(bitree t)
{
    bitree sta[maxsize]; //声明一个栈数组，用于实现LIFO结点调用
    int top = -1;
    while (t || top != -1)
    {
        while (t)
        { //一路向左
            cout << t->data << " ";
            sta[++top] = t;
            t = t->lchild;
        }
        if (top != -1)
        { //取出一个右结点
            t = sta[top--];
            t = t->rchild;
        }
    }
}

//中序遍历非递归算法
void InOrderTraverse_NoRecursion(bitree t)
{
    bitree sta[maxsize];
    int top = -1;
    while (t || top != -1)
    { //当前访问结点不为空或栈不为空
        while (t)
        {
            sta[++top] = t;
            t = t->lchild;
        }
        if (top != -1)
        { //栈不为空
            t = sta[top--];
            cout << t->data << " ";
            t = t->rchild;
        }
    }
}

//后序遍历非递归算法（方法之一）
//已知：先序：DLR，后序：LRD,左右孩子颠倒的先序遍历:DRL
//将DRL压栈后再输出即为LRD，从而实现后序遍历非递归实现算法
void PostOrderTraverse_NoRecursion(bitree t)
{
    bitree sta[maxsize]; //二叉树结点栈
    char sta2[maxsize];  //将二叉树左右孩子颠倒后先序输出顺序进行压栈
    int top = -1, top2 = 0;
    while (t || top != -1)
    {
        while (t)
        {
            sta2[top2++] = t->data;
            sta[++top] = t;
            t = t->rchild;
        }
        if (top != -1)
        {
            t = sta[top--];
            t = t->lchild;
        }
    }
    while (top2--)
        cout << sta2[top2] << " ";
}

//求指定结点的路径
void PreOrder_LeavesRoute(bitree t, char c, int level)
{
    static char sta[10]; //用于存放从根结点到当前结点的动态更新的栈
    if (!t)
        return; //当前访问的结点为空，直接返回
    sta[level++] = t->data;
    if (t->data == c)
    { //当前访问结点中的数据即为所要找的值
        int i = 0;
        cout << "根节点到当前结点的路径为:";
        while (i < level - 1)
            cout << sta[i++] << "->";
        cout << sta[i] << endl;
        return;
    }
    PreOrder_LeavesRoute(t->lchild, c, level);
    PreOrder_LeavesRoute(t->rchild, c, level);
    level--;
}
void Find(bitree t)
{
    system("cls");
    cout << "请输入指定结点的值：";
    char c;
    cin >> c;
    PreOrder_LeavesRoute(t, c, 0);
}

//销毁二叉树，释放申请的空间
void BiTreedestroy(bitree t)
{
    if (t)
    {
        if (t->lchild)
            BiTreedestroy(t->lchild);
        if (t->rchild)
            BiTreedestroy(t->rchild);
        delete t;
        t = NULL;
    }
    cout << "退出成功";
    getchar();
    exit(0);
}

void menu()
{
    bitree bt = NULL; //根节点指针
    while (1)
    {
        cout << "\t\t\t菜单内容：\n\
			1. 建立二叉树存储结构\n\
			2. 求二叉树的前序遍历\n\
			3. 求二叉树的中序遍历\n\
			4. 求二叉树的后序遍历\n\
			5. 求指定结点的路径\n\
			6. 退出系统\n\
			请选择：1 – 6： ";
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            build(bt);
            cout << "创建成功！";
            getchar();
            getchar();
            break;
        case 2:
            PreOrderTraverse_NoRecursion(bt);
            getchar();
            getchar();
            break;
        case 3:
            InOrderTraverse_NoRecursion(bt);
            getchar();
            getchar();
            break;
        case 4:
            PostOrderTraverse_NoRecursion(bt);
            getchar();
            getchar();
            break;
        case 5:
            Find(bt);
            getchar();
            getchar();
            break;
        case 6:
            BiTreedestroy(bt);
            break;
        default:
            exit(0);
            break;
            ;
        }
        system("cls"); //清屏函数
    }
}
int main()
{
    menu();
    return 0;
}
