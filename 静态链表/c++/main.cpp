#include <iostream>
using namespace std;

// 静态链表的一个特点就是需要提前估算所需空间
#define MAXSIZE 100

struct node {
    int data; // 这里可以使用模板存储各种元素
    int cur;
};

class StaticLinkList {
    private:
        node* nodes;
        // node* empty_nodes;
        int length;

    public:
        StaticLinkList() {
            this->length = 0;
            this->nodes = new node[MAXSIZE];
            // 静态链表第一个节点的游标指向第一个空节点，其余每个空节点指向下一个空节点
            for(int i = 0; i < MAXSIZE - 1; i++) {
                this->nodes[i].cur = i + 1;
            }
            // 静态链表最后一个节点游标指向头节点，若为0则说明当前链表为空
            this->nodes[MAXSIZE - 1].cur = 0;
            this->nodes[MAXSIZE - 1].data = 0;
        }

        ~StaticLinkList() {
            if(this->nodes != NULL) {
                delete[] this->nodes;
                this->nodes = NULL;
            }
        }

        // 从静态链表的尾部插入
        void push_back(int val) {
            if(this->nodes[0].cur == 0) { // [0]元素的cur为0说明链表为满
                cout << "out of arrange" << endl;
                return;
            }

            if(this->nodes[MAXSIZE - 1].cur == 0) { // 最后一个坐标的cur为0说明链表为空
                this->nodes[1].data = val;
                this->nodes[1].cur = 0; //尾节点的cur标记为0
                this->nodes[MAXSIZE - 1].cur = 1; // 指向头结点
                this->nodes[0].cur = 2; // 指向最新的空节点
                this->nodes[MAXSIZE - 1].data++; //记录当前链表的长度
                return;
            }

            // this->nodes[0].cur指向第一个空节点,this->nodes[this->nodes[0].cur].cur就是下一个空节点的index
            int next_empty = this->nodes[this->nodes[0].cur].cur;
            int index = 0; // 尾结点的index
            for(int i = 1; i < MAXSIZE - 1; i++) {
                if(this->nodes[i].cur == 0) {
                    index = i;
                    break;
                }
            }
            this->nodes[index].cur = this->nodes[0].cur;
            this->nodes[this->nodes[0].cur].data = val;
            this->nodes[this->nodes[0].cur].cur = 0;
            this->nodes[0].cur = next_empty;
            this->nodes[MAXSIZE - 1].data++;
        }

        void print() {
            int index = this->nodes[MAXSIZE - 1].cur;
            if(index == 0) {
                return;
            }
            cout << this->nodes[index].data << " ";
            while(this->nodes[index].cur) {
                index = this->nodes[index].cur;
                cout << this->nodes[index].data << " ";
            }
            cout << endl;
        }

        void insert(int index, int val) {
            if(index < 0 || index > this->nodes[MAXSIZE - 1].data) {
                cout << "out of index" << endl;
                return;
            }

            if(this->nodes[0].cur == MAXSIZE - 1) {
                cout << "out of arrange" << endl;
                return;
            }

            int next_empty = this->nodes[this->nodes[0].cur].cur; // 取再下一个空节点备用
            int j = this->nodes[MAXSIZE - 1].cur; // 拿到头结点的index
            for(int i = 0; i < index; i++) {
                j = this->nodes[j].cur; //拿到要插入位置的index，index从逻辑上的0开始，index为0即视为在头结点插入
            }
            // 把插入位置的原数据挪到最近空节点上
            this->nodes[this->nodes[0].cur].data = this->nodes[j].data;
            this->nodes[this->nodes[0].cur].cur = this->nodes[j].cur;
            this->nodes[j].data = val;
            this->nodes[j].cur = this->nodes[0].cur;
            this->nodes[0].cur = next_empty;
            this->length++;
        }

        void remove(int index) {
            if (this->nodes[MAXSIZE - 1].cur == 0) {
                cout << "empty linklist" << endl;
                return;
            }

            if(index < 1 || index > this->nodes[MAXSIZE - 1].data) {
                cout << "out of index" << endl;
                return;
            }

            int empty_cur = this->nodes[0].cur; // 拿到当前的空节点，因为删除会更新一个空节点，这个新的空节点需要指向当前的空节点

            int j = this->nodes[MAXSIZE - 1].cur; // 拿到头结点的index
            if (index == j) {
                this->nodes[MAXSIZE - 1].cur = this->nodes[j].cur;// 说明删掉了头节点，更新MAXSIZE-1位置的数据即可
                this->nodes[0].cur = j;
                this->nodes[j].cur = empty_cur;
                this->nodes[MAXSIZE - 1].data--; // 更新长度
                return;
            }

            for(int i = 0; i < index - 2; i++) {
                j = this->nodes[j].cur; //拿到要删除的上一个位置
            }

            // 直接将
            int next_cur = this->nodes[this->nodes[j].cur].cur;
            this->nodes[0].cur = this->nodes[j].cur;
            // 相当于p->next = p->next->next
            this->nodes[j].cur = next_cur;
            // 将最新的空节点的cur指向上一个最新空节点的index
            this->nodes[this->nodes[0].cur].cur = empty_cur;
            this->nodes[MAXSIZE - 1].data--;
        }

        int getLength() {
            return this->nodes[MAXSIZE - 1].data;
        }
};

int main() {
    StaticLinkList sll;
    sll.push_back(1);
    sll.push_back(2);
    sll.push_back(3);
    sll.push_back(4);
    sll.push_back(5);
    cout << sll.getLength() << endl;
    sll.print();

    sll.remove(5);
    cout << sll.getLength() << endl;
    sll.print();

    return 0;
}
// 可以发现静态链表删除节点后不用将节点内存回收，而是会等待复用