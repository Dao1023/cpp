#include <iostream>

using namespace std;

// �������ڵ�ṹ�嶨��
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ������������������ĵݹ麯��
TreeNode* buildTree(int inorder[], int& index, int start, int end) {
    if (start > end) return nullptr;  // �߽����������ؿ���

    // �ݹ�ʱ������������еĵ�ǰ����λ�û�ȡ�ڵ�ֵ
    int rootValue = inorder[index++];
    TreeNode* root = new TreeNode(rootValue);

    // ����������
    root->left = buildTree(inorder, index, start, rootValue - 1);

    // ����������
    root->right = buildTree(inorder, index, rootValue + 1, end);

    return root;
}

// ������������ӡ�����������
void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->val << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};  // �������������˳��
    int n = sizeof(inorder) / sizeof(inorder[0]); // ���鳤��
    int index = 0;
    TreeNode* root = buildTree(inorder, index, 0, n - 1);

    cout << "Inorder traversal of the built tree: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}

