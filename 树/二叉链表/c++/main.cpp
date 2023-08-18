#include <iostream>
#include <queue> // 层级遍历需要用队列实现
using namespace std;

 struct Node {
    char data;
    Node* lchild;
    Node* rchild;
    Node(char d);
};

Node::Node(char d) {
    this->data = d;
    this->lchild = NULL;
    this->rchild = NULL;
}

// 每个节点打印数据为自己左孩子右孩子
void printNode(Node*& node) {
    if(node->lchild == NULL && node->rchild == NULL) {
        cout << node->data << "0" << "0" << " ";
    } else if(node->lchild == NULL) {
        cout << node->data << "0" << node->rchild->data << " ";
    } else if(node->rchild == NULL) {    
        cout << node->data << node->lchild->data << "0" << " ";
    } else {
        cout << node->data << node->lchild->data << node->rchild->data << " ";
    }
}


class Tree {
    public:
        Node* root;
        // 使用前序遍历的方式来初始化二叉树
        void preOrder_push(Node*& root) { // 这里必须使用引用来传递指针，否则传参和实参只是值拷贝
            char root_data;
            cout << "input data:";
            cin >> root_data;
            if(root_data == '0') { // 输入0则代表该节点为NULL
                return;
            }
            root = new Node(root_data);
            // 采用递归的方法，每次先输入根，再去找左孩子，最后找右孩子
            cout << root_data << " lchild" << endl;;
            preOrder_push(root->lchild);

            cout << root_data << " rchild:" << endl;
            preOrder_push(root->rchild); 
        }

        void preOrder_print(Node* root) {
            // 注意要在调用时传入根节点，不能在函数内去获取根节点
            if(root == NULL) {
                return;
            }
            // cout << root->data << " "; // 根
            printNode(root);
            preOrder_print(root->lchild); // 左
            preOrder_print(root->rchild); // 右
        }

        void midOrder_print(Node* root) {
            if(root == NULL) {
                return;
            }
            midOrder_print(root->lchild); // 左
            // cout << root->data << " "; // 根
            printNode(root);
            midOrder_print(root->rchild); // 右
        }

        void postOrder_print(Node* root) {
            if(root == NULL) {
                return;
            }
            postOrder_print(root->lchild); // 左
            postOrder_print(root->rchild); // 右
            // cout << root->data << " "; // 根
            printNode(root);
        }

        void levelOrder_print(Node* root) {
            queue<Node*> q;
            q.push(root);
            Node* temp;
            while(q.size()) {
                temp = q.front();
                cout << temp->data << " ";
                q.pop();
                if(temp->lchild != NULL) {
                    q.push(temp->lchild);
                }
                if(temp->rchild != NULL) {
                    q.push(temp->rchild);
                }
            }
        }
};

int main() {
    Tree tree;
    tree.preOrder_push(tree.root);
    tree.preOrder_print(tree.root);
    cout << endl;
    tree.midOrder_print(tree.root);
    cout << endl;
    tree.postOrder_print(tree.root);
    cout << endl;
    tree.levelOrder_print(tree.root);

    return 0;
}