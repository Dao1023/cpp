#include <iostream>

class Stack {
private:
    static const int MAX = 1000;  // 栈的最大容量
    int top;  // 指向栈顶的指针
    int arr[MAX];  // 存储栈元素的数组

public:
    Stack() : top(-1) {}  // 构造函数，初始化栈顶指针

    // 判断栈是否为空
    bool isEmpty() {
        return (top < 0);
    }

    // 向栈中添加元素
    bool push(int x) {
        if (top >= (MAX - 1)) {
            std::cout << "栈溢出" << std::endl;
            return false;
        } else {
            arr[++top] = x;
            std::cout << x << " 被推入栈" << std::endl;
            return true;
        }
    }

    // 移除栈顶元素
    int pop() {
        if (top < 0) {
            std::cout << "栈下溢" << std::endl;
            return 0;
        } else {
            int x = arr[top--];
            return x;
        }
    }

    // 获取栈顶元素
    int peek() {
        if (top < 0) {
            std::cout << "栈为空" << std::endl;
            return 0;
        } else {
            return arr[top];
        }
    }

    // 获取栈的大小
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << s.pop() << " 被从栈中移除" << std::endl;  // 输出 30
    std::cout << "当前栈顶元素: " << s.peek() << std::endl;  // 输出 20
    std::cout << "当前栈的大小: " << s.size() << std::endl;  // 输出 2

    return 0;
}
