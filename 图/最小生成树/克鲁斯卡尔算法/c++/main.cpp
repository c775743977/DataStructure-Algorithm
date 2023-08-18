#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXVEX 100 // 最大顶点数量
#define INFINITY 65535 // 表示正无穷

struct Edge {
    int begin;
    int end;
    int weight;
    Edge(int begin, int end, int weight);
};

Edge::Edge(int begin, int end, int weight) {
    this->begin = begin;
    this->end = end;
    this->weight = weight;
};

bool myCompare(const Edge e1, const Edge e2) {
    return e1.weight < e2.weight;
}

class Graph {
    public:
        char g_vexs[MAXVEX];
        int g_arcs[MAXVEX][MAXVEX];
        int numVexs, numArcs;
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
                // this->g_arcs[y][x] = w;
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

        void MST() {
            int m, n = 0;
            vector<Edge> v;
            int parent[this->numVexs];

            for(int i = 0; i < this->numVexs; i++) {
                for(int j = 0; j < this->numVexs; j++) {
                    if(this->g_arcs[i][j] != 0 && this->g_arcs[i][j] != INFINITY) {
                        v.push_back(Edge(i, j, g_arcs[i][j]));
                    }
                }
            }

            sort(v.begin(), v.end(), myCompare);
            for(vector<Edge>::iterator it = v.begin(); it != v.end(); it++) {
                cout << it->begin << " " << it->end << " " << it->weight << endl;
            }

            for(int i = 0; i < this->numVexs; i++) {
                parent[i] = 0;
            }

            for(int i = 0; i < this->numArcs; i++) {
                m = find(parent, v[i].begin);
                n = find(parent, v[i].end);
                if(m != n) {
                    cout << m << "," << n << " " << v[i].weight << "\t";
                    parent[m] = n;
                }
            }
        }

        int find(int *parent, int index) {
            while(parent[index] != 0) {
                index = parent[index];
            }
            return index;
        }

};

int main() {
    Graph g;

    g.MST();

    return 0;
}