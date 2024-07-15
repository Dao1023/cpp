void BiTree(BiTree *p, int deep) {
    if (p == NULL) return 0;
    else if (p->lchild == NULL && p->rchild == NULL) {
        
}


void InOrder(BiTree *p) {
    if (p == NULL) return 0;
    printf("(");
    InOrder(p->lchild);
    printf("%c", p->data);
    InOrder(p->rchild);
    printf(")");
}
