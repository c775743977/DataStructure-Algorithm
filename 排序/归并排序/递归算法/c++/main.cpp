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

        void MergeSort() {
            Msort(this->arr, this->arr, 0, this->len - 1);
        }

        void Msort(int SR[], int TR1[], int s, int t) {
            int m;
            int TR2[MAXSIZE ];
            if(s == t) {
                TR1[s] = this->arr[s];
            } else {
                m = (s + t) / 2;
                Msort(SR, TR2, s , m);
                Msort(SR, TR2, m + 1, t);
                Merge(TR2, TR1, s, m, t);
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