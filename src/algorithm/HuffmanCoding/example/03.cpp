#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class Node {
public:
    char c;     //结点字符，非字符结点默认为'z' + 1 = '{'
    int value;  //结点出现频率
    int idx;    //结点出现最早时间
    Node* left;
    Node* right;

    bool operator<(const Node& node) {
        if (value == node.value) {
            return idx < node.idx;
        }
        return value < node.value;
    }
};

Node* character[26];  //二十六个英文字母的结点数组，没出现的字母为空
Node* nodes[1000];  //结点集合，每次从中挑选最小结点
int tot = 0;        //结点集合规模
char str[10000];
int main() {
    cin >> str;
    int len = strlen(str);

    for (int i = 0, c; i < len; i++) {
        c = str[i] - 'a';
        if (character[c] ==
            NULL) {  //如果该字母第一次出现，则创建结点并且记录第一次出现位置
            character[c] = new Node();
            character[c]->c = str[i];
            character[c]->idx = i;
            character[c]->value = 1;
            character[c]->left = NULL;
            character[c]->right = NULL;
            nodes[tot++] = character[c];  //加入结点集合
        } else {
            character[c]->value++;
        }
    }
    int cnt = tot;  //总结点数量

    int first;
    int second;
    Node* node;
    while (cnt-- > 1) {  //总结点数量每次减一，总共循环cnt-1次
        first = -1;
        second = -1;
        for (int j = 0; j < tot; j++) {
            if (nodes[j] == NULL) {
                continue;
            }
            if (first == -1 ||
                *nodes[j] <
                    *nodes[first]) {  //注意这里是取值进行比较而非直接比较指针
                second = first;
                first = j;
            } else if (second == -1 || *nodes[j] < *nodes[second]) {
                second = j;
            }
        }
        //创建新的结点
        node = new Node();
        node->c = 'z' + 1;
        node->value = nodes[first]->value + nodes[second]->value;
        node->left = nodes[first];
        node->right = nodes[second];
        node->idx = len++;

        nodes[tot++] = node;  //添加新结点
        nodes[first] = NULL;  //删除合并的结点
        nodes[second] = NULL;
    }

    Node* root = nodes[tot - 1];  //哈夫曼树根节点为最后加入集合的结点
}