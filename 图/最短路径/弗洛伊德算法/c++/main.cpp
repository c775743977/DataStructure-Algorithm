#include <iostream>

using namespace std;

#define MAXVEX 100 // 最大顶点数量
#define INFINITY 65535 // 表示正无穷

class Graph {
    public:
        char g_vexs[MAXVEX];
        int g_arcs[MAXVEX][MAXVEX];
        int numVexs, numArcs;
        int g_indexs[MAXVEX][MAXVEX];
        int g_paths[MAXVEX][MAXVEX];
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

        void get_paths() {
            for(int i = 0; i < this->numVexs; i++) {
                for(int j = 0; j < this->numVexs; j++) {
                    this->g_indexs[i][j] = j;
                    this->g_paths[i][j] = this->g_arcs[i][j];
                }
            }

            for(int i = 0; i < this->numVexs; i++) {
                for(int j = 0; j < this->numVexs; j++) {
                    for(int k = 0; k < this->numVexs; k++) {
                        if(this->g_paths[j][k] > this->g_paths[j][i] + this->g_paths[i][k]) {
                            this->g_paths[j][k] = this->g_paths[j][i] + this->g_paths[i][k];
                            this->g_indexs[j][k] = this->g_indexs[j][i];
                        }
                    }
                }
            }

            for(int i = 0; i < this->numVexs; i++) {
                for(int j = 0; j < this->numVexs; j++) {
                    cout << this->g_indexs[i][j] << " ";
                }
                cout << endl;
            }

            for(int i = 0; i < this->numVexs; i++) {
                for(int j = 0; j < this->numVexs; j++) {
                    cout << this->g_paths[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Graph g;
    g.get_paths();

    return 0;
}