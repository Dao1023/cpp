#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <vector>
#include <array>
using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

template <typename T>
struct BitNode
{
    /* data */
    T data;
    BitNode *lchild;
    BitNode *rchild;
    BitNode(T data) : data(data), lchild(nullptr), rchild(nullptr){};
};

template <typename T>
class BinaryTree
{
private:
    int count;
    void PreOrderTraverse(BitNode<T> *node, void (*visit)(T)); //用于先序遍历二叉树
    void MidOrderTraverse(BitNode<T> *node, void (*visit)(T)); //用于中序遍历二叉树
    void EndOrderTraverse(BitNode<T> *node, void (*visit)(T)); //用于后序遍历二叉树
    void LevelOrderTraverse(void (*visit)(T));                 //用于层序遍历二叉树
    void PreOrderTraverseStack(void (*visit)(T));              //用栈先序遍历二叉树
    void MidOrderTraverseStack(void (*visit)(T));              //用栈中序遍历二叉树
public:
    BitNode<T> *root;
    BinaryTree() : root(nullptr), count(0){};                   //无参构造函数
    BinaryTree(const BitNode<T> *&rhs) : root(rhs), count(0){}; //复制构造函数
    bool Empty();                                               // 判断二叉树是否为空
    void Traverse(int key, void (*visit)(T));                   //用于遍历二叉树
    void CreateTree(BitNode<T> *&ptr);
};

template <typename T>
inline bool BinaryTree<T>::Empty()
{
    if (this->root = nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
void BinaryTree<T>::Traverse(int key, void (*visit)(T))
{
    if (key == 1)
    {
        PreOrderTraverse(this->root, visit);
    }
    else if (key == 2)
    {
        MidOrderTraverse(this->root, visit);
    }
    else if (key == 3)
    {
        EndOrderTraverse(this->root, visit);
    }
    else if (key == 4)
    {
        LevelOrderTraverse(visit);
    }
    else if (key == 5)
    {
        PreOrderTraverseStack(visit);
    }
    else if (key == 6)
    {
        MidOrderTraverseStack(visit);
    }
    else if (key == 7)
    {
        EndOrderTraverseStack(visit);
    }
}

template <typename T>
void BinaryTree<T>::PreOrderTraverse(BitNode<T> *node, void (*visit)(T))
{
    if (node)
    {
        visit(node->data);
        PreOrderTraverse(node->lchild, visit);
        PreOrderTraverse(node->rchild, visit);
    }
}

template <typename T>
void BinaryTree<T>::MidOrderTraverse(BitNode<T> *node, void (*visit)(T))
{
    if (node)
    {
        MidOrderTraverse(node->lchild, visit);
        visit(node->data);
        MidOrderTraverse(node->rchild, visit);
    }
}

template <typename T>
void BinaryTree<T>::EndOrderTraverse(BitNode<T> *node, void (*visit)(T))
{
    if (node)
    {
        EndOrderTraverse(node->lchild, visit);
        EndOrderTraverse(node->rchild, visit);
        visit(node->data);
    }
}

template <typename T>
void BinaryTree<T>::LevelOrderTraverse(void (*visit)(T))
{
    BitNode<T> *queue[2 * count];
    BitNode<T> *tmp;
    int l = 0, r = 0;
    queue[r++] = this->root;
    while (l < r)
    {
        tmp = queue[l++];
        visit(tmp->data);
        if (tmp->lchild != nullptr)
        {
            queue[r++] = tmp->lchild;
        }
        if (tmp->rchild != nullptr)
        {
            queue[r++] = tmp->rchild;
        }
    }
}

template <typename T>
void BinaryTree<T>::PreOrderTraverseStack(void (*visit)(T))
{
    BitNode<T> *stack[2 * count];
    BitNode<T> *tmp = this->root;
    int l = 0;
    while ((tmp != nullptr) || l > 0)
    {
        while (tmp != nullptr)
        {
            visit(tmp->data);
            stack[l++] = tmp;
            tmp = tmp->lchild;
        }
        tmp = stack[--l];
        tmp = tmp->rchild;
    }
}

template <typename T>
void BinaryTree<T>::MidOrderTraverseStack(void (*visit)(T))
{
    BitNode<T> *stack[2 * count];
    BitNode<T> *tmp = this->root;
    int l = 0;
    while ((tmp != nullptr) || l > 0)
    {
        while (tmp != nullptr)
        {
            stack[l++] = tmp;
            tmp = tmp->lchild;
        }
        tmp = stack[--l];
        visit(tmp->data);
        tmp = tmp->rchild;
    }
}

template <typename T>
void BinaryTree<T>::CreateTree(BitNode<T> *&ptr)
{
    T ch;
    ch = getchar();
    if (ch == '#')
    {
        ptr = nullptr;
    }
    else
    {
        count++;
        ptr = new BitNode<T>(ch);
        ptr->data = ch;
        CreateTree(ptr->lchild);
        CreateTree(ptr->rchild);
    }
}
template <typename T>
void visit(T data)
{
    cout << data << " ";
}
#endif
