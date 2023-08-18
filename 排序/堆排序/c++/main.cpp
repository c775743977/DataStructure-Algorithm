#include <iostream>
using namespace std;

#define MAXSIZE 1000

// 首先堆排序是基于完全二叉树，堆排序的完全二叉树只有两种，要么根节点大于其左右子树的所有节点，要么根节点小于其左右子树
// 根据完全二叉树的定义，根节点k，那么其左孩子为2k，右孩子为2k+1

class Data {
    public:
        int arr[MAXSIZE];
        int len;

        Data() {
            this->len = 0;
        }

        void Push_back(int key) {
            // 这里len必须先+1，即arr[0]是空置不用的。因为根据完全二叉树的特性，左孩子为2k，右孩子为2k+1
            // 如果以arr[0]开始，那么根节点坐标为0,无法计算其左右孩子的坐标
            this->arr[++this->len] = key;
        }

        // 对长度length的k节点为根节点进行转换为大顶堆
        void HeapAdjust(int k, int length) {
            int temp = this->arr[k];
            // i=k*2即i取k节点的左孩子
            for(int i = k * 2; i <= length; i *= 2) {
                // arr[i] < arr[i+1]即说明右孩子大于左孩子，则取右孩子的坐标
                if(i < length && this->arr[i] < this->arr[i + 1]) {
                    i += 1;
                }
                // 判断根节点是否大于其左右孩子的最大值，如果大于就说明已满足大顶堆
                if(temp > this->arr[i]) {
                    break;
                }
                this->arr[k] = this->arr[i];
                k = i;
            }

            this->arr[k] = temp;
        }

        void Swap(int i, int j) {
            int temp = this->arr[i];
            this->arr[i] = this->arr[j];
            this->arr[j] = temp;
        }

        void HeapSort() {
            // 先将数据初始化为大顶堆，根据完全二叉树的定义，节点数/2即为非叶子节点数。初始化时，只需要对非叶子节点执行即可让整个数据变成大顶堆
            for(int i = this->len / 2; i > 0; i--) {
                this->HeapAdjust(i, this->len);
                this->Print();
            }
            // 然后对大顶堆进行排序
            
            for(int i = this->len; i > 1; i--) {
                this->Swap(1, i); // 大顶堆根节点即arr[1]始终为最大值，就让最后一个元素与arr[1]交换位置
                this->HeapAdjust(1, i - 1); // 然后将最后一个元素踢出，再对剩余的子数组排序，直到所有元素有序
            }

        }

        void Print() {
            for(int i = 1; i <= this->len; i++) {
                cout << this->arr[i] << " ";
            }

            cout << endl;
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

    data.HeapSort();

    data.Print();

    return 0;
}