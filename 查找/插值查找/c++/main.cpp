#include <iostream>
using namespace std;

int Interpolation_Search(int *a, int len, int key) {
    int low = 0;
    int high = len - 1;
    while(high >= low) {
        int mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]); // 与折半查找唯一的区别
        if(key > a[mid]) {
            low = mid + 1;
        } else if(key < a[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int a[10] = {1, 16, 24, 35, 47, 59, 62, 73, 88, 99};
    cout << Interpolation_Search(a, sizeof(a) / sizeof(a[0]), 63) << endl;

    return 0;
}