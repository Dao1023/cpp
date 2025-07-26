if (T->lchild == NULL && T->rchild == NULL) {
    WPL += length * T->weight;
} else {
    WPL += WPL(T->lchild) + WPL(T->rchild);
}
