#include <iostream>

using namespace std;

// 二叉树节点结构体定义
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 中序遍历建立二叉树的递归函数
TreeNode* buildTree(int inorder[], int& index, int start, int end) {
    if (start > end) return nullptr;  // 边界条件，返回空树

    // 递归时从中序遍历序列的当前索引位置获取节点值
    int rootValue = inorder[index++];
    TreeNode* root = new TreeNode(rootValue);

    // 构建左子树
    root->left = buildTree(inorder, index, start, rootValue - 1);

    // 构建右子树
    root->right = buildTree(inorder, index, rootValue + 1, end);

    return root;
}

// 辅助函数：打印树的中序遍历
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};  // 假设中序遍历的顺序
    int n = sizeof(inorder) / sizeof(inorder[0]); // 数组长度
    int index = 0;
    TreeNode* root = buildTree(inorder, index, 0, n - 1);

    cout << "Inorder traversal of the built tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

