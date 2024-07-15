// #include <cstdlib>
#include <iostream>
using namespace std;

#define MaxVertexNum 100

typedef char VertexType;
typedef int EdgeType;
/**
 * Matrix Graph 邻接矩阵图
 * 简单应用中可直接用二维数组作为数据结构，不需要顶点信息
 * 无向图是对称矩阵，规模大后可采用压缩存储
 * 邻接矩阵空间复杂度 O(|V|^2)
 */
typedef struct {
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

// BFS 伪代码
// void BFSTraverse(Graph G) {
//     // 置零访问标记数组
//     for (int i = 0; i < n; i++) {
//         visited[i] = false;
//     }
//     // 初始化访问队列
//     InitQueue(Q);
//     // 遍历每个连通分量
//     for (int i = 0; i < n; i++) {
//         if (!visited[i]) {
//             BFS(G, i);
//         }
//     }
// }

// void BFS(Graph G, int v) {}

int randint(int n) {
    return rand() % (n + 1);
}

int main() {
    MGraph G;
    G.vexnum = 10;
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            G.edge[i][j] = randint(1);
        }
    }

    // 输出邻接矩阵
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum; j++) {
            cout << G.edge[i][j] << " ";
        }
        cout << endl;
    }

    /**
     * 渲染图数据结构的设想
     * 渲染一个圆，均分给图的每个顶点
     * 用图的边顶点连线表示
     */
}