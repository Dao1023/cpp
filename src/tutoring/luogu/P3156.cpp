#include <iostream>
#include <vector>

// using namespace std;

int main() {
    
}



/*
#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<std::vector<int>> dataRows; // 用于存储每一行的数据
    std::string line; // 用于读取一行文本

    while (std::getline(std::cin, line)) { // 读取一行数据
        std::istringstream iss(line); // 将字符串流用于分割
        std::vector<int> row; // 存储当前行的数据

        int value;
        while (iss >> value) { // 从行中读取整数值
            row.push_back(value); // 将值添加到当前行的向量中
        }

        dataRows.push_back(row); // 将当前行添加到数据行的向量中
    }

    // 输出每一行的数据
    for (const auto& row : dataRows) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
 */