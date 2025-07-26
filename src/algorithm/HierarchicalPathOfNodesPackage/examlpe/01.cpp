int flag = 1;
void FindBiTree(BiTree T, char p) //查找指定结点，并且记录路径
{
    if (T == NULL) //二叉树为空
    {
        return;
    }
    if (flag)
    {
        Push(T->data); //入栈
        if (T->data == p)
        {
            printf("指定结点%c\n", T->data);
            flag = 0; //找到指定结点，标志取0
            return;
        }
    }
    FindBiTree(T->lChild, p);
    FindBiTree(T->rChild, p);
    if ((!flag == 0)) //左右子树为空时
    {
        Pop();
    }
}

void way(BiTree T, char p) //输出路径
{
    int i;
    char temp[max];
    flag = 1; //标志为1
    if (T == NULL)
        return;
    FindBiTree(T, p);
    for (i = 0; S.top >= 0; i++)
    {
        temp[i] = Pop(); // 4
    }
    printf("根结点到%c路径为长度为%d\n", p, i - 1);
    printf("根结点到%c的路径为：\n", p);
    for (i--; i >= 0; i--) // 3
    {
        printf("%c", temp[i]); //输出正确路径
        if (i > 0)
            printf("->");
    }
    printf("\n");
