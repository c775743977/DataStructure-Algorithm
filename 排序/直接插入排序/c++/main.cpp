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

        void InsertSort() {
            int j;
            for(int i = 1; i < this->len; i++) {
                int temp = this->arr[i];
                if(this->arr[i] < this->arr[i - 1]) {
                    for(j = i - 1; this->arr[j] > temp && j >= 0; j--) {
                        this->arr[j + 1] = this->arr[j];
                    }
                    this->arr[j + 1] = temp;
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
    data.InsertSort();
    data.print();

    return 0;
}