#include <iostream>
#include <stack>
#include <vector>
#include <sstream> // 用于将字符转换为整型
using namespace std;

// c++可以直接使用STL库中的stack容器

// 自定义优先级，因为ASCII码无法判断优先级
int getPriority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '(') { // 左括号优先级最高
        return 3;
    } else { // 右括号优先级最低
        return 0;
    }
}

class Calculator {
    private:
        stack<char> c_stack;
        // vector容器用于储存结果，stack容器只用于转换
        vector<char> c_vector;
        string c_expression;

    public:
        Calculator(string expression) {
            this->c_expression = expression;
        }

        void printVector() {
            cout << "postfix res:";
            for (vector<char>::iterator it = this->c_vector.begin(); it != this->c_vector.end(); it++) {
                cout << *it;
            }

            cout << endl;
        }

        void to_postfix() {
            for (int i = 0; i < this->c_expression.size(); i++) {
                if (this->c_expression[i] < '0') { // +-*/()的ASCII码值都是小于0的
                    // 当栈为空或者当前符号优先级大于栈顶符号时，直接入栈
                    if (this->c_stack.empty() || this->c_stack.top() == '(' ||getPriority(this->c_expression[i]) > getPriority(this->c_stack.top())) {
                        this->c_stack.push(this->c_expression[i]);
                        this->c_vector.push_back(' '); // 以便分割数字
                    } else {
                            while (!this->c_stack.empty() && this->c_stack.top() != '(') {
                                char c = this->c_stack.top();
                                this->c_stack.pop(); // pop返回是void
                                this->c_vector.push_back(c);
                            }
                        // 需要判断，如果是右括号，则只出栈到左括号，而不是全部出栈
                        if (this->c_expression[i] == ')') {
                            this->c_stack.pop(); // 左括号出栈
                        } else {
                            this->c_stack.push(this->c_expression[i]);
                        }
                    }
                } else {
                    this->c_vector.push_back(this->c_expression[i]);
                }
            }

            // 遍历过表达式后栈内还有符号没取出，这个时候全部出栈即可
            while(!this->c_stack.empty()) {
                char c = this->c_stack.top();
                this->c_stack.pop();
                this->c_vector.push_back(c);
            }
        }

        // 经过中缀转后缀，stack容器一定为空
        int compute() {
            stack<int> post_stack;
            string str;
            for (vector<char>::iterator it = this->c_vector.begin(); it != this->c_vector.end(); it++) {
                if (*it <= '9' && *it >= '0') { // 如果一个数字后面还是数字，就说明这是同一个数字的不同位，就写入str中
                    str.push_back(*it);
                } else { // 如果不是数字则要把之前存在str中的数字转为int存入栈中
                    int num, num1, num2 = 0;
                    if (!str.empty()) {
                        istringstream ss(str);
                        ss >> num;
                        post_stack.push(num);
                    }
                    // 记得清空str
                    str.clear();

                    if (*it != ' ') { // 如果为空格，则不需要任何处理
                        num1 = post_stack.top();
                        post_stack.pop();
                        num2 = post_stack.top();
                        post_stack.pop();
                        switch(*it) {
                        case '+':
                            post_stack.push(num2 + num1);
                            break;
                        case '-':
                            post_stack.push(num2 - num1);
                            break;
                        case '*':
                            post_stack.push(num2 * num1);
                            break;
                        case '/':
                            post_stack.push(num2 / num1);
                            break;
                        }
                    }
                }
            }
            return post_stack.top();
        }
};

void test() {
    Calculator my_cal("10+(3-1)*3+10/2");

    my_cal.to_postfix();

    my_cal.printVector();

    cout << "res:" << my_cal.compute() << endl;
    
}

int main() {
    test();

    return 0;
}