#include <iostream>
#include <queue>
using namespace std;

#define MAXVEX 100 // 最大顶点数量
#define INFINITY 65535 // 表示正无穷

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

        void DFS(int i) {

            this->visited[i] = true;
            cout << this->g_vexs[i] << " ";

            // 无向图
            // for(int j = 0; j < this->numVexs; j++) {
            //     if(!this->visited[j] && this->g_arcs[i][j] == 1) {
            //         this->DFS(j);
            //     }
            // }

            // 有向图
            for(int j = 0; j < this->numVexs; j++) {
                if(!this->visited[j] && this->g_arcs[i][j] != 0 && this->g_arcs[i][j] != INFINITY) {
                    this->DFS(j);
                }
            }
        }

        void DFSTraverse() {
            for(int i = 0; i < this->numVexs; i++) {
                this->visited[i] = false;
            }

            for(int i = 0; i < this->numVexs; i++) {
                if(!this->visited[i]) {
                this->DFS(i);
                }
            }
        }

        void BFSTraverse() {
            for(int i = 0; i < this->numVexs; i++) {
                this->visited[i] = false;
            }

            queue<int> q;

            // 连通图可以不用外层循环，从任意顶点开始就能遍历整个图了
            // if(!this->visited[0]) {
            // this->visited[0] = true;
            // cout << this->g_vexs[0] << " ";
            // q.push(0);
            
            for(int i = 0; i < this->numVexs; i++) {
                if(!this->visited[i]) {
                    this->visited[i] = true;
                    cout << this->g_vexs[i] << " ";
                    q.push(i);
                }
                while(!q.empty()) {
                    int index = q.front();
                    q.pop();
                    for(int i = 0; i < this->numVexs; i++) {
                        if(!this->visited[i] && this->g_arcs[index][i] != INFINITY && this->g_arcs[index][i] != 0) {
                            q.push(i);
                            this->visited[i] = true;
                            cout << this->g_vexs[i] << " ";
                        }
                    }
                }
            }
        }
};

int main() {
    Graph g;

    g.print();

    g.DFSTraverse();

    cout << endl;

    g.BFSTraverse();

    return 0;
}