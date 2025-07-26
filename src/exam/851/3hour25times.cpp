/**
 * 非常有趣的一个功能
 * 我们用 GPT4o 是每3小时只有25次机会，我就想这大概率是队列
 * 这里模拟了一个队列的实现，非常有意思
 */

#include <iostream>
#include <ctime>
#include <chrono>
#include "Quene3.h"

const int MAX_EXECUTIONS = 25;
const int TIME_WINDOW = 30;

bool limitedFunction(SqQueue &Q) {
    std::time_t currentTime = std::time(nullptr);

    // 这里很巧妙，如果队列有东西，那看看有没有头尾相差很多可以出队的，直到没有就 break，如果不写 break 会卡死的
    while (!isEmptyQueue(Q)) {
        std::time_t frontTime = Q.data[Q.front];
        if (currentTime - frontTime < TIME_WINDOW) break;
        DeQueue(Q, frontTime);
    }

    if ((Q.rear + 1) % Q.maxSize != Q.front) {
        EnQueue(Q, currentTime);
        std::cout << "Function executed at: " << std::ctime(&currentTime);
        return true;
    } else {
        std::time_t nextAvailableTime = Q.data[Q.front] + TIME_WINDOW;
        std::cout << "Function execution limit reached. Try again at: " << std::ctime(&nextAvailableTime);
        return false;
    }
}

int main() {
    SqQueue q;
    InitQueue(q, MAX_EXECUTIONS + 1); // 预留一个空间判断满队列

    char input;
    while (1) {
        std::cin >> input;
        limitedFunction(q);
    }

    DestoryQueue(q);

    return 0;
}
