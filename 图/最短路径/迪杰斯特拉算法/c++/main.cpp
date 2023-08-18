#include <iostream>
#include <stack>
using namespace std;

#define MAXVEX 100 // 最大顶点数量
#define INFINITY 65535 // 表示正无穷

class Graph {
    public:
        char g_vexs[MAXVEX];
        int g_arcs[MAXVEX][MAXVEX];
        int numVexs, numArcs;

        // 储存v0到各点的路径
        int g_indexs[MAXVEX];

        // 储存v0到各点的距离
        int g_paths[MAXVEX];

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

        void getPath() {
            // 用于标记v0到某个顶点的最短路径是否已存在
            int flags[MAXVEX];

            int index = 0;

            // 初始化
            for(int i = 0; i < this->numVexs; i++) {
                flags[i] = 0; // i为对应顶点，0表示还没求出最短路径
                this->g_indexs[i] = -1; // -1代表到vi顶点还没有得到最短路径
                this->g_paths[i] = this->g_arcs[0][i]; // 初始化v0到vi的距离(权重)
            }

            flags[0] = 1; // v0到v0不存在最短路径，直接标记为1

            for(int i = 1; i < this->numVexs; i++) {
                int min = MAXVEX;
                for(int j = 0; j < this->numVexs; j++) {
                    // 找出与当前顶点连接的最小权值与对应的顶点
                    if(!flags[j] && g_paths[j] < min) { // !flags[j]表示已经找到最小权值的顶点直接跳过
                        index = j;
                        min = g_paths[j];
                    }
                }
                flags[index] = 1; // 标记该顶点
                for(int k = 0; k < this->numVexs; k++) {
                    // 如果v0到当前顶点的最短路径加上与当前顶点相连顶点权值小于v0到这些顶点的权值，则需要更新最短距离
                    if(!flags[k] && min + this->g_arcs[index][k] < this->g_paths[k]) {
                        this->g_paths[k] = this->g_arcs[index][k] + min;
                        this->g_indexs[k] = index; // 到vk的最短路径前驱顶点更新为vindex
                    }
                }
            }
            for(int i = 0; i < this->numVexs; i++) {
                cout << this->g_indexs[i] << " ";
            }
            cout << endl;
            for(int i = 0; i < this->numVexs; i++) {
                cout << this->g_paths[i] << " ";
            }
            cout << endl;
        }

        void path_to(int index) {
            cout << "v0到" << "v" << index << "的最短距离为" << this->g_paths[index] << endl;
            stack<int> s;
            while(index != -1) {
                s.push(index);
                index = this->g_indexs[index];
            }
            cout << "v0";
            while(!s.empty()) {
                cout << "->v" << s.top();
                s.pop();
            }
        }
};

int main() {
    Graph g;
    g.getPath();
    g.path_to(8);

    return 0;
}