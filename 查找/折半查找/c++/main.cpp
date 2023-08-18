#include <iostream>
using namespace std;

int Binary_Search(int *a, int len, int key) {
    int low = 0;
    int high = len - 1;
    while(high >= low) {
        int mid = (low + high) / 2;
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
    int index = Binary_Search(a, 10, 62);
    cout << index << endl;

    return 0;
}