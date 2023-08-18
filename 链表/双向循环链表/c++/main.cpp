#include <iostream>
using namespace std;

struct Node {
    Node* last;
    int data;
    Node* next;
};

class DulLinkList {
    private:
        Node* head;
    
    public:
        DulLinkList() {
            this->head = new Node();
            this->head->data = 0;
            this->head->last = this->head;
            this->head->next = this->head;
        }

        ~DulLinkList() {
            Node* temp = this->head->next;
            Node* p;
            while (temp != this->head) {
                p = temp;
                temp = temp->next;
                delete p;
            }

            this->head->data++; // head节点的data储存链表长度
        }

        void push_back(int val) {
            Node* p = new Node();
            p->data = val;

            // 双向链表的尾插法时间复杂度变为O(1)
            p->next = this->head;
            p->last = this->head->last;
            this->head->last->next = p;
            this->head->last = p;
            this->head->data++;
        }

        void push_front(int val) {
            Node* p = new Node();
            p->data = val;
            p->last = this->head;
            p->next = this->head->next;
            this->head->next->last = p;
            this->head->next = p;
            this->head->data++;
        }

        void insert(int index, int val) {
            // 插入范围为1-length+1
            if (index < 1 || index > this->head->data + 1) {
                cout << "out of index" << endl;
                return;
            }

            Node* p = new Node();
            p->data = val;

            // 获取第index个节点的前一个节点
            Node* temp = this->head;
            for (int i = 1; i < index; i++) {
                temp = temp->next;
            }

            p->last = temp;
            p->next = temp->next;
            temp->next->last = p;
            temp->next = p;

            this->head->data++;
        }

        int remove(int index) {
            if (index < 1 || index > this->head->data) {
                cout << "out of index" << endl;
                return 0;
            }

            // 获取第index个节点
            Node* temp = this->head;
            for (int i = 1; i <= index; i++) {
                temp = temp->next;
            }

            temp->last->next = temp->next;
            temp->next->last = temp->last;
            int val = temp->data;
            delete temp;
            this->head->data--;
            return val;
        }

        void print() {
            Node* temp = this->head->next;
            while (temp != head) {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }
};

int main() {
    DulLinkList dll;
    dll.insert(1, 1);
    dll.insert(2, 2);
    dll.insert(3, 3);
    dll.insert(4, 4);
    dll.insert(5, 5);

    dll.print();

    return 0;
}