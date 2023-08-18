#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* lchild;
    Node* rchild;
    Node(int key);
};

Node::Node(int key) {
    this->data = key;
    this->lchild = NULL;
    this->rchild = NULL;
}

Node* SearchBST(Node* root, int key, Node* f) {
    if(root == NULL) {
        return f;
    } else if(key == root->data) {
        return root;
    } else if(key > root->data) {
        return SearchBST(root->rchild, key, root);
    } else {
        return SearchBST(root->lchild, key, root);
    }
}

// 这里必须加上引用，不然第一次插入时根节点的地址不会更改
bool InsertBST(Node*& root, int key) {
    Node* node = SearchBST(root, key, NULL);
    if(node != NULL && node->data == key) {
        return false;
    }

    Node* newNode = new Node(key);
    if(root == NULL) {
        root = newNode;
    } else if(key > node->data) {
        node->rchild = newNode;
    } else if(key < node->data) {
        node->lchild = newNode;
    }
    return true;
}

// 删除需要分三种情况
void Delete(Node* root) {
    Node* temp = NULL;
    Node* pre = NULL;

    if(root->rchild == NULL) {
        temp = root->lchild;
        // 不可以直接root = root->lchild
        root->data = temp->data;
        root->lchild = temp->lchild;
        root->rchild = temp->rchild;
        delete temp;
    } else if(root->lchild == NULL) {
        temp = root->rchild;
        root->data = temp->data;
        root->lchild = temp->lchild;
        root->rchild = temp->rchild;
        delete temp;
    } else {
        temp = root->lchild;
        pre = root; 
        // pre一直指向temp的双亲
        while(temp->rchild != NULL) {
            pre = temp;
            temp = temp->rchild;
        }

        if(pre != root) { // 如果pre==root说明root左孩子就是用来代替root位置，这种情况的处理会不一样
            pre->rchild = temp->lchild;
            root->data = temp->data;
            delete temp;
        } else {
            root->data = temp->data;
            root->lchild = temp->lchild;
            delete temp;
        }
    }
}


bool DeleteBST(Node* root, int key) {
    if(root == NULL) {
        return false;
    }

    if(key == root->data) {
        Delete(root);
        return true;
    } else if(key > root->data) {
        DeleteBST(root->rchild, key);
    } else {
        DeleteBST(root->lchild, key);
    }
}

void print_MiddleOrder(Node* root) {
    if(root != NULL) {
        print_MiddleOrder(root->lchild);
        cout << root->data << " ";
        print_MiddleOrder(root->rchild);
    }
}

void print_PreOrder(Node* root) {
    if(root != NULL) {
        cout << root->data << " ";
        print_PreOrder(root->lchild);
        print_PreOrder(root->rchild);
    }
}

int main() {
    int a[10] = {3,2,1,4,5,6,7,10,9,8};
    Node* tree = NULL;
    for(int i = 0; i < 10; i++) {
        InsertBST(tree, a[i]);
    }

    DeleteBST(tree, 88);

    print_MiddleOrder(tree);
    cout << endl;
    print_PreOrder(tree);

    return 0;
}