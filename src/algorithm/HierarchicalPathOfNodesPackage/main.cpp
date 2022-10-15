#include <iostream>

// 类型名与静态变量
#define ElemType char

static unsigned long int NODESIZE = 1024;

// 定义节点
struct BTNode {
    ElemType data;
    struct BTNode* Lchild;
    struct BTNode* Rchild;
};

// 定义二叉树
class BinaryTree {
   public:
};

int BinTree::CreateBinTree(BinaryTree* this) {
    ElemType UserInput;
    cin >> UserInput;
    this->data = UserInput;

    CreateBinTree()
}

void main() {
    return 0;
}