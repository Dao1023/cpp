// typedef int ElemType;

// 这个结构体是节点，是树的组成单位
typedef struct Node {
    int data;            // int Node::data
    struct Node *left;   // Node *Node::left
    struct Node *right;  // Node *Node::right
} Node;

int main() {
    Node A;
    Node B;
    Node C;

    A.left = &B;
    A.right = &C;

    return 0;
}