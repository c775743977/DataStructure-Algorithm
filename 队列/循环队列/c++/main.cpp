#include <iostream>
#include <vector>
using namespace std;

class Queue {
    public:
        vector<int> q_data;
        int q_rear;
        int q_front;

    public:
        // 队列的实际存储空间为max-1，因为循环队列需要空出一个空间来方便区别队满和队空
        // 或者也可以引入变量flag来记录当read==front时是队满还是队空
        Queue(int max) {
            this->q_data.resize(max + 1);
            this->q_front = 0;
            this->q_rear = 0;
        }

        bool empty() {
            if(this->q_front == this->q_rear) {
                return true;
            } else {
                return false;
            }
        }

        int getHead() {
            if(this->empty()) {
                return 0;
            }

            return this->q_data[this->q_front];
        }

        bool full() {
            if((this->q_rear+1)%this->q_data.size() == this->q_front) {
                cout << (this->q_rear+1)%this->q_data.size() << endl;
                cout << "front:" << this->q_front << endl;
                return true;
            } else {
                return false;
            }
        }

        void push_back(int data) {
            if(this->full()) {
                cout << "out of range" << endl;
                return;
            }

            this->q_data[this->q_rear] = data;
            this->q_rear = (this->q_rear + 1) % this->q_data.size();
        }

        int pop_front() {
            if(this->empty()) {
                return 0;
            }

            int data = this->q_data[this->q_front];
            this->q_data[this->q_front] = 0;
            this->q_front = (this->q_front + 1) % this->q_data.size();

            return data;
        }

        int getLength() {
            return (this->q_rear + this->q_data.size() - this->q_front) % this->q_data.size();
        }

        void print() {
            for(vector<int>::iterator it = this->q_data.begin(); it != this->q_data.end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
};

void test() {
    Queue q(5);
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.print();
    q.push_back(4);
    q.push_back(5);
    q.print();
    q.pop_front();
    q.print();
    q.pop_front();
    q.print();
    cout << q.getLength() << endl;
    q.push_back(6);
    cout << q.getLength() << endl;
    q.print();
    q.push_back(7);
    cout << q.getLength() << endl;
    q.print();
}

int main() {
    test();

    return 0;
}