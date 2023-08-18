#include <iostream>
using namespace std;

template<typename T>
class MyStack {
    private:
        T* m_data;
        int m_top;
        int m_max;

    public:
        // max为栈的总容量
        MyStack(int max) {
            this->m_max = max;
            this->m_top = 0;
            this->m_data = new T[m_max];
        }

        ~MyStack() {
            if (this->m_data != NULL) {
                delete[] this->m_data;
                this->m_data = NULL;
            }
        }

        void push(T data) {
            if (this->m_top >= this->m_max) {
                cout << "out of index" << endl;
                return;
            }

            this->m_data[this->m_top] = data;
            this->m_top++;
        }

        T pop() {
            if (this->m_top == 0) {
                cout << "empty stack" << endl;
                return NULL;
            }
            
            return this->m_data[--this->m_top];
        }

        bool empty() {
            if (this->m_top == 0) {
                return true;
            } else {
                return false;
            }
        }

        int getLength() {
            return this->m_top;
        }

        T getTop() {
            if (this->m_top == 0) {
                cout << "empty stack" << endl;
                return NULL;
            }
            return this->m_data[this->m_top - 1];
        }

        void clear() {
            this->m_top == 0;
        }

        void print() {
            for (int i = 0; i < this->m_top; i++) {
                cout << this->m_data[i] << " ";
            }

            cout << endl;
        }
};

void test() {
    MyStack<int> ms(100);
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);
    ms.push(6);
    ms.push(7);

    cout << ms.empty() << endl;
    cout << ms.getLength() << endl;
    cout << ms.getTop() << endl;

    ms.print();
    cout << ms.pop() << endl;
    ms.print();
}

void test2() {
    MyStack<string> ms(100);
    ms.push("aaa");
    ms.push("zxc");
    ms.push("2d2qasd");
    ms.push("zxc");
    ms.push("gb");
    ms.push("kb");
    ms.push("ok");

    cout << ms.empty() << endl;
    cout << ms.getLength() << endl;
    cout << ms.getTop() << endl;

    ms.print();
    cout << ms.pop() << endl;
    ms.print();    
}

int main() {
    test2();

    return 0;
}