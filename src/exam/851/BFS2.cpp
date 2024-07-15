/**
 * 2024-7-31
 * 今晚目标
 * [] 把图的所有代码写一遍
 * [] 最好能把明天的也预习一下
 */

#include <iostream>
#include <Quene2.h>

using namespace std;

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;


// 先把图的数据结构写出来，V+E
typedef struct {
    VertexType vex[MaxVertexNum] = {'1', '2', '3', '4', '5', '6'};
    EdgeType edge[MaxVertexNum][MaxVertexNum] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 1, 0, 1},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0},
    };
    int vexnum, arcnum;     // 不知道干什么用的
} Graph;



// 这个是伪代码
void BFStraverse(Graph G) {
    int n = MaxVertexNum;
    bool visited[n];
    VertexType visit[MaxVertexNum];

    // 已访问
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // 准备一个临时队列，用完就扔
    SqQueue Q;
    InitQueue(Q)

    // 遍历
    for (int i = 0; i < n; i++) {
        // 这段代码在书本上是写了一个 BFS(G,i) 函数的伪代码
        // 这里为了执行方便放在了一起
        if (!visited[i]) {
            // 书上用的是 visit(i) 伪代码，我这里用数组直接存了
            visit[i] = G.vex[i];
            visited[i] = true;

            EnQueue(Q, i);
            while (!isEmptyQueue(Q)) {
                DeQueue(Q, v);
                for ()
            }
        }
    }
}




int main() {

    Graph G;
    

    BFStraverse(G);
}