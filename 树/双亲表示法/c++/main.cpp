#include <iostream>
using namespace std;

struct Node {
    char data;
    int parent;
    int rightsib;
    Node(char d, int p, int r);
    Node();
};

Node::Node(char d, int p, int r) {
    this->data = d;
    this->parent = p;
    this->rightsib = r;
}

Node::Node() {

}

class Tree {
    public:
        Node* nodes;
        int root;
        int len;
        Tree(int MAX) {
            this->nodes = new Node[MAX];
            this->len = 0;
            this->root = 0;
        }

        void add(Node node) {
            this->nodes[this->len++] = node;
        }

        void print() {
            for(int i = 0; i < this->len; i++) {
                cout << i << " " << this->nodes[i].data << " " << this->nodes[i].parent << " " << this->nodes[i].rightsib << endl;
            }
        }
};

int main() {
    Tree tree(10);
    tree.add(Node('A', -1, -1));
    tree.add(Node('B', 0, 2));
    tree.add(Node('C', 0, -1));
    tree.add(Node('D', 1, -1));
    tree.add(Node('E', 2, 5));
    tree.add(Node('F', 2, -1));
    tree.add(Node('G', 3, 7));
    tree.add(Node('H', 3, 8));
    tree.add(Node('I', 3, -1));
    tree.add(Node('J', 4, -1));

    tree.print();

    return 0;
}