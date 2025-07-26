// 数据结构基础

#include <iostream>
#include <string>
using namespace std;

int main() {

    // 数据由数据元素组成，数据元素是基本单位，用于描述个体
    // 数据项是最小单位，比如说实例的属性，类的变量
    // 数据对象是相同性质的数据元素集合
    typedef struct student {
        string name;
        int num;
        float score;
    } Student;

    return 0;
}
