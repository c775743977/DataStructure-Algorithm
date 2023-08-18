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

        void SelectSort() {
            int min;
            for(int i = 0; i < this->len - 1; i++) {
                min = i;
                for(int j = i + 1; j < this->len; j++) {
                    if(this->arr[min] > this->arr[j]) {
                        min = j;
                    }
                }
                if(min != i) {
                    this->Swap(i, min);
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
    data.SelectSort();
    data.print();

    return 0;
}