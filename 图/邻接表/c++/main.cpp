#include <iostream>
#include <queue>
using namespace std;

#define MAXSIZE 100

struct Arc {
    int index;
    int weight;
    Arc* next;
};

struct Vex {
    char data;
    Arc* firstArc;
};

class Graph {
    public:
        int g_numVex, g_numArc;
        Vex* g_vexs;
        bool g_visited[MAXSIZE];
        Graph() {
            this->g_vexs = new Vex[MAXSIZE];
            cout << "input vex number:";
            cin >> this->g_numVex;
            cout << "input arc number:";
            cin >> this->g_numArc;
            for(int i = 0; i < this->g_numVex; i++) {
                cout << "input vex" << i << ":";
                cin >> this->g_vexs[i].data;
                this->g_vexs[i].firstArc = NULL;
            }

            int x,y,w = 0;
            for(int i = 0; i < this->g_numArc; i++) {
                cout << "input arc" << i << " x:";
                cin >> x;
                cout << "input arc" << i << " y:";
                cin >> y;
                cout << "input arc" << i << " w:";
                cin >> w;
                Arc* arc1 = new Arc;
                arc1->index = y;
                arc1->next = this->g_vexs[x].firstArc;
                this->g_vexs[x].firstArc = arc1;
                arc1->weight = w;
                
                // 无向图
                Arc* arc2 = new Arc;
                arc2->index = x;
                arc2->next = this->g_vexs[y].firstArc;
                this->g_vexs[y].firstArc = arc2;
                arc2->weight = w;
            }
        }

        void print() {
            for(int i = 0; i < this->g_numVex; i++) {
                cout << this->g_vexs[i].data << " ";
                Arc* arc = this->g_vexs[i].firstArc;
                while(arc != NULL) {
                    cout << arc->index << " " << arc->weight << " ";
                    arc = arc->next;
                }
                cout << endl;
            }
        }

        void DFS(int index) {
            this->g_visited[index] = true;
            cout << this->g_vexs[index].data << " ";

            Arc* arc = this->g_vexs[index].firstArc;
            while(arc != NULL) {
                if(!this->g_visited[arc->index]) {
                    this->DFS(arc->index);
                }
                arc = arc->next;
            }
        }

        void DFSTraverse() {
            for(int i = 0; i < this->g_numVex; i++) {
                this->g_visited[i] = false;
            }

            for(int i = 0; i < this->g_numVex; i++) {
                if(!this->g_visited[i]) {
                    this->DFS(i);
                }
            }
        }

        void BFSTraverse() {
            for(int i = 0; i < this->g_numVex; i++) {
                this->g_visited[i] = false;
            }

            queue<int> q;
            for(int i = 0; i < this->g_numVex; i++) {
                if(!this->g_visited[i]) {
                    q.push(i);
                    this->g_visited[i] = true;
                    cout << this->g_vexs[i].data << " ";
                }
                while(!q.empty()) {
                    int index = q.front();
                    q.pop();
                    Arc* arc = this->g_vexs[index].firstArc;
                    while(arc != NULL && !this->g_visited[arc->index]) {
                        q.push(arc->index);
                        this->g_visited[arc->index] = true;
                        cout << this->g_vexs[arc->index].data << " ";
                        arc = arc->next;
                    }
                }
            }
        }
};

int main() {
    Graph g;

    g.print();
    cout << endl;

    g.DFSTraverse();
    cout << endl;

    g.BFSTraverse();

    return 0;
}