#include <iostream>
using namespace std;

#define LH 1 // 左高
#define EH 0 // 等高
#define RH -1 // 右高

struct Tree {
    int data;
    int bf;
    Tree* lchild;
    Tree* rchild;
};

Tree* SearchBST(Tree* root, int key, Tree* f) {
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

void R_Rotate(Tree* tree) {
    Tree* temp = tree->lchild;
    int temp_data = 0;
    Tree* tree_rchild = tree->rchild;
    tree->lchild = temp->lchild;
    tree->rchild = temp;
    temp_data = tree->data;
    tree->data = temp->data;
    temp->data = temp_data;
    temp->lchild = temp->rchild;
    temp->rchild = tree_rchild;
}

void L_Rotate(Tree* tree) {
    Tree* temp = tree->rchild;
    int temp_data = 0;
    Tree* tree_lchild = tree->lchild;
    tree->rchild = temp->rchild;
    tree->lchild = temp;
    temp_data = tree->data;
    tree->data = temp->data;
    temp->data = temp_data;
    temp->rchild = temp->lchild;
    temp->lchild = tree_lchild;
}

void LeftBalance(Tree* tree) {
    Tree* L = tree->lchild;
    if(L->bf == LH) {
        tree->bf = EH;
        L->bf = EH;
        R_Rotate(tree);
    } else if(L->bf == RH) {
        Tree* Lr = L->rchild;
        switch(Lr->bf) {
        case EH:
            L->bf = EH;
            tree->bf = EH;
            break;
        case RH:
            L->bf = LH;
            tree->bf = EH;
            break;
        case LH:
            L->bf = EH;
            tree->bf = RH;
            break;
        }
        Lr->bf = EH;
        L_Rotate(L);
        R_Rotate(tree);
    }
}

void RightBalance(Tree* tree) {
    Tree* R = tree->rchild;
    if(R->bf == RH) {
        tree->bf = EH;
        R->bf = EH;
        L_Rotate(tree);
    } else if(R->bf == LH) {
        Tree* Rl = R->lchild;
        switch(Rl->bf) {
        case EH:
            R->bf = EH;
            tree->bf = EH;
            break;
        case RH:
            tree->bf = LH;
            R->bf = EH;
            break;
        case LH:
            tree->bf = EH;
            R->bf = RH;
            break;
        }
        Rl->bf = EH;
        R_Rotate(R);
        L_Rotate(tree);
    }
}

bool InsertAVL(Tree*& tree, int key, bool& taller) {
    if(tree == NULL) {
        tree = new Tree();
        tree->data = key;
        tree->lchild = NULL;
        tree->rchild = NULL;
        tree->bf = EH;
        taller = true;
    } else {
        if(tree->data == key) {
            taller = false;
            return false;
        }

        if(tree->data > key) {
            bool res = InsertAVL(tree->lchild, key, taller);
            if(!res) {
                return false;
            }

            if(taller) {
                switch(tree->bf) {
                case EH:
                    tree->bf = LH;
                    taller = true;
                    break;
                case LH:
                    LeftBalance(tree);
                    taller = false;
                    break;
                case RH:
                    tree->bf = EH;
                    taller = false;
                    break;
                }
            }
        } else {
            bool res = InsertAVL(tree->rchild, key, taller);
            if(!res) {
                return false;
            }

            if(taller) {
                switch(tree->bf) {
                case EH:
                    tree->bf = RH;
                    taller = true;
                    break;
                case LH:
                    tree->bf = EH;
                    taller = false;
                    break;
                case RH:
                    RightBalance(tree);
                    taller = false;
                    break;
                }
            }
        }
    }
    return true;
}

// 删除需要分三种情况
void Delete(Tree* root) {
    Tree* temp = NULL;
    Tree* pre = NULL;

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


bool DeleteBST(Tree* root, int key) {
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

void print_MiddleOrder(Tree* root) {
    if(root != NULL) {
        print_MiddleOrder(root->lchild);
        cout << root->data << " ";
        print_MiddleOrder(root->rchild);
    }
}

void print_PreOrder(Tree* root) {
    if(root != NULL) {
        cout << root->data << " ";
        print_PreOrder(root->lchild);
        print_PreOrder(root->rchild);
    }
}

int main() {
    Tree* tree = NULL;
    int a[10] = {3,2,1,4,5,6,7,10,9,8};
    bool taller;
    for(int i = 0; i < 10; i++) {
        InsertAVL(tree, a[i], taller);
    }

    print_MiddleOrder(tree);
    cout << endl;
    print_PreOrder(tree);

    return 0;
}