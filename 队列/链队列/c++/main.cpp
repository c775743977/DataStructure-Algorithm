#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int data;
    Node(int val);
};

Node::Node(int val) {
    this->data = val;
    this->next = NULL;
}

class Queue {
    private:
        Node* head;
    public:
        Queue() {
            this->head = new Node(0);
        }

        ~Queue() {
            if (this->head->next != NULL) {
                Node* temp = this->head->next;
                this->head->next = this->head->next->next;
                delete temp;
                temp = NULL;
            }

        }

        int getLength() {
            return this->head->data;
        }

        void push_back(int val) {
            Node* p = new Node(val);
            Node* temp = this->head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = p;
            this->head->data++;
        }

        bool empty() {
            if (this->head->next == NULL) {
                return true;
            } else {
                return false;
            }
        }

        int pop_front() {
            if (this->empty()) {
                cout << "empty queue!" << endl;
                return 0;
            }

            int val = this->head->next->data;
            Node* temp = this->head->next;
            this->head->next = this->head->next->next;
            delete temp;
            this->head->data--;
            return val;
        }

        void print() {
            Node* temp = this->head->next;
            while(temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

void test() {
    Queue q;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.print();
    cout << q.getLength() << endl;
    cout << q.empty() << endl;
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    cout << q.getLength() << endl;
    cout << q.empty() << endl;
}

int main() {
    test();

    return 0;
}