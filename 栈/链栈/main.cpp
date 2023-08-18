#include <iostream>
using namespace std;

// 其实链栈就是个单链表
struct node {
    int data;
    node* next;
};

class MyStack {
    private:
        node* head;
        int length;

    public:
        MyStack() {
            this->head = NULL;
            this->length = 0;
        }

        ~MyStack() {
            node* temp = NULL;
            if (this->head == NULL) {
                return;
            }

            if (this->head->next != NULL) {
                temp = this->head->next;
                head->next = head->next->next;
                delete temp;
            }

            delete head;
            this->head = NULL;
        }

        void push(int data) {
            node* p = new node();
            p->data = data;
            p->next = NULL;
            node* temp = this->head;
            while (temp != NULL) {
                temp = temp->next;
            }
            temp = p;

            this->length++;
        }

        int pop() {
            if (this->head == NULL) {
                cout << "empty stack" << endl;
                return 0;
            }

            int data = 0;
            node* temp = this->head;
            while (temp->next != NULL) {
                temp = temp->next;
            }

            data = temp->data;
            delete temp;
            temp = NULL;
            this->length--;
        }

        bool empty() {
            if (this->head == NULL) {
                return true;
            } else {
                return false;
            }
        }

        int getLength() {
            return this->length;
        }

        int getTop() {
            node* temp = this->head;

            if (this->head == NULL) {
                cout << "empty stack" << endl;
                return 0;
            }

            while(temp->next != NULL) {
                temp = temp->next;
            }
            return temp->data;
        }

        void clear() {
            node* temp = NULL;
            if (this->head == NULL) {
                return;
            }

            if (this->head->next != NULL) {
                temp = this->head->next;
                head->next = head->next->next;
                delete temp;
            }

            delete head;
            this->head = NULL;
            this->length = 0;
        }

        void print() {
            node* temp = this->head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }
}