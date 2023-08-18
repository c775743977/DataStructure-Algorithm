#include <iostream>
using namespace std;

#define MAXVEX 100 // 最大顶点数量
#define INFINITY 65535 // 表示正无穷

// 最小生成树基于邻接矩阵
class Graph {
    public:
        char g_vexs[MAXVEX];
        int g_arcs[MAXVEX][MAXVEX];
        int numVexs, numArcs;
        bool visited[MAXVEX];
        Graph() {
            cout << "input vex number:";
            cin >> this->numVexs;
            cout << "input arc number:";
            cin >> this->numArcs;
            
            // 初始化顶点数据
            for(int i = 0; i < this->numVexs; i++) {
                cout << "input vex" << i << ":";
                cin >> this->g_vexs[i];
            }

            // 初始化边数据
            for(int i = 0; i < this->numVexs; i++) {
                for(int j = 0; j < this->numVexs; j++) {
                    if(i == j) {
                        this->g_arcs[i][j] = 0;
                    } else {
                        this->g_arcs[i][j] = INFINITY;
                    }
                }
            }

            // 输入边数据
            for(int i = 0; i < this->numArcs; i++) {
                int x, y, w = 0;
                cout << "input x:";
                cin >> x;
                cout << "input y:";
                cin >> y;
                cout << "input w:";
                cin >> w;
                this->g_arcs[x][y] = w;
                // 无向图
                this->g_arcs[y][x] = w;
            }
        }

        void print() {
            for(int i = 0; i < this->numVexs; i++) {
                cout << this->g_vexs[i] << " ";
            }
            cout << endl;

            for(int i = 0; i < this->numVexs; i++) {
                for(int j = 0; j < this->numVexs; j++) {
                    cout << this->g_arcs[i][j] << "\t";
                }
                cout << endl;
            }
        }

        // 仅打印出树的结构，要返回一个树结构还需要构建树类
        void MCST_print() {
            int min, index;
            // 存放当前到各个顶点的最小权值
            int weights[MAXVEX];
            // 存放对应最小权值的顶点坐标
            int indexs[MAXVEX];

            // 初始化，从0坐标的顶点开始
            for(int i = 0; i < this->numVexs; i++) {
                weights[i] = this->g_arcs[0][i]; // 存入0号顶点的所有权值
                indexs[i] = 0; // 每个权值都对应0号顶点
            }

            for(int i = 1; i < this->numVexs; i++) {
                for(int k = 0; k < this->numVexs; k++) {
                    cout << weights[k] << "-" << indexs[k] << "  ";
                }
                cout << endl;
                min = INFINITY; // min用于比较获取最小权值
                index = 0; // index用于记录下一次连接的顶点坐标
                for(int j = 1; j < this->numVexs; j++) {
                    if(weights[j] != 0 && weights[j] < min) { // 如果权重为0，则说明是已经连接过的顶点，需要跳过
                        min = weights[j];
                        index = j;
                    }
                }
                // 经过上面循环获取到了最小权值以及最小权值的对应顶点坐标
                cout << indexs[index] << "," << index << " "; // indexs[index]->index即为当前要连接的路线
                weights[index] = 0; // 表明这个节点已经连接，下次遍历需要跳过

                // 现在连线已经完成，需要加入新顶点的信息
                for(int j = 1; j < this->numVexs; j++) {
                    // 如果weights[j] == 0说明已经连接，需要跳过。
                    // this->g_arcs[index][j] < weights[i]说明新顶点到i顶点有更小的权值，所以需要更新到weights数组
                    if(weights[j] != 0 && this->g_arcs[index][j] < weights[j]) {
                        weights[j] = this->g_arcs[index][j];
                        indexs[j] = index;
                    } 
                }
            }
        }
};


int main() {
    Graph g;
    g.MCST_print();

    return 0;
}