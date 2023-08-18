#include <iostream>
using namespace std;

template<typename T>
class My_arr {
    private:
        T* m_data;
        int m_MAXSIZE;
        int m_length;
    public:
        My_arr(int size) {
            this->m_MAXSIZE = size;
            this->m_length = 0;
            this->m_data = new T[size];
        }

        ~My_arr() {
            if (this->m_data != NULL) {
                delete[] this->m_data;
                this->m_data = NULL;
            }
        }

        // 插入还涉及是否超出容量，以及超出之后的扩容机制有待实现
        void insert(T data, int pos = -1) {
            if (this->m_length == this->m_MAXSIZE) {
                cout << "out of index" << endl;
                return;
            }

            if (pos > this->m_length) {
                cout << "error" << endl;
                return;
            }

            // pos == -1说明没有输入插入位置，那么默认插到最后
            if (pos == -1 || pos == this->m_length) {
                this->m_data[this->m_length] = data;
            } else {
                for (int i = this->m_length; i > pos; i--) {
                    this->m_data[i] = this->m_data[i - 1];
                }
                this->m_data[pos] = data;
            }

            this->m_length++;
        }

        void remove(int pos = -1) {
            if (this->m_length == 0 || pos >= this->m_length) {
                cout << "out of index" << endl;
                return;
            }

            if (pos == -1 || pos == this->m_length - 1) {
                this->m_length--;
                return;
            }

            for (int i = pos; i < this->m_length - 1; i++) {
                this->m_data[i] = this->m_data[i + 1];
            }
            this->m_length--;
        }

        void printArr() {
            if (this->m_length == 0) {
                return;
            }

            for (int i = 0; i < this->m_length; i++) {
                cout << this->m_data[i] << " ";
            }

            cout << endl;
        }

        // 重写拷贝构造函数，防止浅拷贝
        My_arr(const My_arr& my_arr) {
            this->m_MAXSIZE = my_arr.m_MAXSIZE;
            this->m_length = my_arr.m_length;
            this->m_data = new T[this->m_MAXSIZE];
            for (int i = 0; i < this->m_length; i++) {
                this->m_data[i] = my_arr.m_data[i];
            }
        }

        // 重载[]运算符
        T operator[](int index) {
            return this->m_data[index];
        }

        // 扩容机制，排序算法，判断两个数组等方法有待实现
};

int main() {
    My_arr<int> my_arr(20);

    my_arr.insert(1);
    my_arr.insert(2);
    my_arr.insert(3);
    my_arr.insert(4);
    my_arr.insert(5);
    my_arr.insert(6);

    my_arr.printArr();

    cout << my_arr[1] << endl;

    my_arr.remove(3);

    my_arr.printArr();

    return 0;
}