#include <iostream>
using namespace std;

struct CNode {
    int index;
    CNode* next;
};

struct Node {
    char data;
    CNode* firstchild;
};

class Tree {
    public:
        Node* nodes;
        int root;
        int len;
        Tree(int MAX) {
            this->nodes = new Node[MAX];
            this->root = 0;
            this->len = 0;
        }


};