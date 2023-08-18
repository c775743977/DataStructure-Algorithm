#include<iostream>
#include<string>
using namespace std;
 
//用类实现单链表
 
class  node
{
public:
	int date;
	node* p_next;
    node() {
        this->date = 0;
        this->p_next = NULL;
    }
};
 
class mylist
{
public:
	mylist()//默认构造函数
	{
		this->m_head = new node;
		this->m_head->date = 0;
		this->m_head->p_next = NULL;
	}

    ~mylist() {
        node* p;
        while(this->m_head->p_next != NULL) {
            p = this->m_head->p_next;
            this->m_head->p_next = this->m_head->p_next->p_next;
            delete p;
        }
        delete this->m_head;
    }

    void push_back(int data) {
        node* p = this->m_head;
        node* q = new node;
        q->date = data;
        while(p->p_next) {
            p = p->p_next;
        }
        p->p_next = q;
    }

    void printLink() {
        node* p = this->m_head->p_next;
        while(p) {
            cout << p->date << " ";
            p = p->p_next;
        }
        cout << endl;
    }

    void remove(int index) {
        int count = 0;
        node* p = this->m_head;
        while(p) {
            if(count == index) {
                node* q = p->p_next;
                p->p_next = p->p_next->p_next;
                delete q;
                break;
            }
            p = p->p_next;
        }
    }
 
private:
	node* m_head;
};

void test2() {
    mylist l;
    l.push_back(1);
    l.push_back(2); 
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.remove(0);
    l.printLink();
}
 
int main()
{
	test2();
	system("pause");
	return 0;
}