#include <iostream>
#include <string>

#define PI 3.1415926
typedef int ElemType;

// 结构体
typedef struct {
    // string name;
    int age;
    bool sex;
    int id;
    double height;
    double weight;
} Student;

int main() {
    // std::cout << "Hello, World!" << std::endl;

    ElemType a = 1;
    int b = 2;

    std::cout << PI << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;


    Student HZY;
    HZY.age = 11;
    HZY.sex = 0;
    HZY.id = 1;
    HZY.height = 1.50;
    HZY.weight = 40.00;

    Student Dao;
    Dao.age = 22;
    Dao.sex = 0;
    Dao.id = 2;
    Dao.height = 1.81;
    Dao.weight = 60.00;

    std::cout << "HZY's age is " << HZY.age << std::endl;
    std::cout << "HZY's sex is " << HZY.sex << std::endl;


    return 0;
}