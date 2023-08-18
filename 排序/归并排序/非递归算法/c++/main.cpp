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
            this->arr[++this->len] = key;
        }

        void Print() {
            for(int i = 1; i <= this->len; i++) {
                cout << this->arr[i] << " ";
            }
            cout << endl;
        }

        void MergeSort() {
            int * TR = new int[this->len + 1];
            int k = 1;
            while(k < this->len) {
                MergePass(this->arr, TR, k, this->len);
                k = 2 * k;
                MergePass(TR, this->arr, k, this->len);
                k = 2 * k;
            }

            for(int i = 1; i <= this->len + 1; i++) {
                cout << TR[i] << " ";
            }
            cout << endl;
        }

        void MergePass(int SR[], int TR[], int s, int n) {
            int i = 1;
            int j;
            while(i <= n - 2 * s + 1) {
                Merge(SR, TR, i, i + s - 1, i + 2 * s - 1);
                i = i + 2 * s;
            }
            if(i < n - s + 1) {
                Merge(SR, TR, i, i + s - 1, n);
            } else {
                for(j = i; j <= n; j++) {
                    TR[j] = SR[j];
                }
            }
        }

        void Merge(int TR[], int SR[], int s, int m, int t) {
            int i, j;
            for(i = s, j = m + 1; s <= m && j <= t; i++) {
                if(TR[s] < TR[j]) {
                    SR[i] = TR[s++];
                } else {
                    SR[i] = TR[j++];
                }
            }

            if(s <= m) {
                for(int k = 0; k <= s - m; k++) {
                    SR[i + k] = TR[s + k];
                }
            }
            if(j <= t) {
                for(int k = 0; k <= t - j; k++) {
                    SR[i + k] = TR[j + k];
                }
            }
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

    data.MergeSort();

    data.Print();

    return 0;
}