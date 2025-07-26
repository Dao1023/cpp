#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// 最大表达式长度
// const int MAX_EXP_LEN = 100;        

enum ABS_ODEVITY {
    ABS_ODD = 1,
    ABS_EVEN = 2,
};

enum PRIO_LV {
    PRIO_LV0 = 0,
    PRIO_LV1 = 1,
    PRIO_LV2 = 2,
    PRIO_LV3 = 3,
    PRIO_LV4 = 4,
};

class Calculate {
public:
    void getFormat();
    int getPrior(char c);
    void getPostfix();
    void calResult();
    void calculate();
    double getResult();

    string infix;

private:
    string runningInfo;      // 运行状态
    string stdInfix;         // 标准表达式
    stack<char> symStack;    // 符号栈
    stack<double> figStack;  // 数字栈
    vector<string> postfix;  // 后缀表达式向量
    double result;

};

// 格式化
void Calculate::getFormat() {
    stdInfix = infix;
}

// 获取运算符号优先级
int Calculate::getPrior(char c) {
    if (c == '+' || c == '-') { return PRIO_LV1; }
    else if (c == '*' || c == '/') { return PRIO_LV2; }
    else if (c == '%' || c == '^') { return PRIO_LV3; }
    else if (c == '!') { return PRIO_LV4; }
    else { return PRIO_LV0; }
}

// 后缀表达式化
void Calculate::getPostfix() {
    
    int absNumeber = ABS_ODD;   //绝对值符号个数的奇偶性
    string tmp;                 // 临时值

    // 入栈操作
    // string.size()返回size_type类型，避免下标运算时的类型溢出
    for (size_t i = 0; i < stdInfix.size(); i++) {
        tmp = "";
        switch (stdInfix[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
            case '!':
            case '|':
            case '(':
            case '[':
            case '{':
            case ')':
            case ']':
            case '}':
            default:
                if (stdInfix[i] >= '0' && stdInfix[i] <= '9') {
                    tmp = stdInfix[i];

                    // 连续数字追加
                    while (i+1 < stdInfix.size() && (stdInfix[i+1] >= '0' && stdInfix[i+1] <= '9' || stdInfix[i] == '.')) {
                        tmp += stdInfix[i+1];
                        i++;

                    // x 改成 x.0
                    if (tmp[tmp.length()-1] == '.') {
                        tmp += '0';
                    }

                    postfix.push_back(tmp);
                }
            
        }
    }

    // 将栈中符号加入后缀表达式
    // push_back 将一个新的元素加到 vector 的最后面
    while (!symStack.empty()) {
        tmp = "";
        tmp += symStack.top();
        postfix.push_back(tmp);
        symStack.pop();
    }
}
}

// 计算后缀表达式
void Calculate::calResult() {
    
}

// 计算总操作
void Calculate::calculate() {
    getFormat();
    getPostfix();
    calResult();
}

// 获取计算结果
double Calculate::getResult() {
    return result;
}

int main() {
    cout << "Hello, world!" << endl;

    Calculate cal;

    while (true) {
        getline(cin, cal.infix);
        cal.calculate();
        cout << cal.getResult() << endl;
    }
}