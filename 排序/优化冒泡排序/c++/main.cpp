#include <iostream>
using namespace std;

#define MAXSIZE 1000

class Data {
    public:
        int arr[MAXSIZE];
        int len;

        Data() {
            this->len = 0;
        }

        void Swap(int i, int j) {
            int temp = this->arr[i];
            this->arr[i] = this->arr[j];
            this->arr[j] = temp;
        }

        void Push_back(int value) {
            this->arr[this->len++] = value;
        }

        void BubbleSort() {
            bool flag = true; // 用于标记是否有数据变动，如果没有变动说明已经有序，不用再执行后面的比较
            for(int i = 0; i < this->len - 1 && flag; i++) {
                flag = false;
                for(int j = this->len - 2; j >= 0; j--) {
                    if(this->arr[j] > this->arr[j + 1]) {
                        this->Swap(j, j + 1);
                        flag = true;
                    }
                }
            }
        }

        void print() {
            for(int i = 0; i < this->len; i++) {
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Data data;
    data.Push_back(12);
    data.Push_back(53);
    data.Push_back(2);
    data.Push_back(16);
    data.Push_back(64);
    data.Push_back(15);
    data.Push_back(46);
    data.Push_back(72);
    data.Push_back(34);
    data.Push_back(44);
    data.BubbleSort();
    data.print();

    return 0;
}