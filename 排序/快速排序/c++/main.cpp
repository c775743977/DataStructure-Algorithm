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

        void Push_back(int key) {
            this->arr[this->len++] = key;
        }

        void Print() {
            for(int i = 0; i < this->len; i++) {
                cout << this->arr[i] << " ";
            }

            cout << endl;
        }

        void Swap(int i, int j) {
            int temp = this->arr[i];
            this->arr[i] = this->arr[j];
            this->arr[j] = temp;
        }

        int Partition(int low, int high) {
            int pivot = this->arr[low];
            while(low < high) {
                while(low < high && this->arr[high] >= pivot) {
                    high--;
                }
                this->Swap(low, high);
                while(low < high && this->arr[low] <= pivot) {
                    low++;
                }
                this->Swap(low, high);
            }

            return high;
        }

        // 优化Partition方法
        int Partiton2(int low, int high) {
            int m = (low + high) / 2;
            if(this->arr[low] > this->arr[high]) {
                this->Swap(low, high);
            }
            if(this->arr[m] > this->arr[high]) {
                this->Swap(m, high);
            }
            if(this->arr[m] > this->arr[low]) {
                this->Swap(m, low);
            }
            int pivot = this->arr[low];
            while(low < high) {
                while(low < high && this->arr[high] >= pivot) {
                    high--;
                }
                this->Swap(low, high);
                while(low < high && this->arr[low] <= pivot) {
                    low++;
                }
                this->Swap(low, high);
            }

            return high;
        }

        // 优化QSort
        void QSort2(int low, int high) {
            while(low < high) {
                int pivot = this->Partiton2(low, high);
                this->QSort2(low, pivot - 1);
                low = pivot + 1;
            }
        }

        void Qsort(int low, int high) {
            if(high > low) {
                int pivot = Partition(low, high);
                this->Qsort(low, pivot - 1);
                this->Qsort(pivot + 1, high);
            }
        }

        void QuickSort() {
            Qsort(0, this->len - 1);
        }
};

int main() {
    Data data;
    data.Push_back(50);
    data.Push_back(10);
    data.Push_back(90);
    data.Push_back(30);
    data.Push_back(70);
    data.Push_back(40);
    data.Push_back(80);
    data.Push_back(60);
    data.Push_back(20);

    data.Print();

    data.QuickSort();

    data.Print();

    return 0;
}