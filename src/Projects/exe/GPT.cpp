#include <fstream>
#include <iostream>
#include <string>

// 定义一个函数用于复制文件
bool copyFile(const std::string &sourcePath, const std::string &destinationPath) {
    std::ifstream src(sourcePath, std::ios::binary); // 以二进制模式打开源文件
    std::ofstream dst(destinationPath, std::ios::binary); // 以二进制模式打开目标文件

    if (!src) { // 检查源文件是否成功打开
        std::cerr << "无法打开源文件: " << sourcePath << std::endl;
        return false;
    }

    if (!dst) { // 检查目标文件是否成功打开
        std::cerr << "无法打开目标文件: " << destinationPath << std::endl;
        return false;
    }

    dst << src.rdbuf(); // 复制文件内容
    return true;
}

int main() {
    std::string pdfSource, pdfDestination, exeSource, exeDestination;

    // 获取用户输入的PDF和EXE文件的路径
    std::cout << "请输入PDF文件的源路径: ";
    std::getline(std::cin, pdfSource);
    std::cout << "请输入PDF文件的目标路径: ";
    std::getline(std::cin, pdfDestination);

    std::cout << "请输入EXE文件的源路径: ";
    std::getline(std::cin, exeSource);
    std::cout << "请输入EXE文件的目标路径: ";
    std::getline(std::cin, exeDestination);

    // 复制PDF文件
    if (copyFile(pdfSource, pdfDestination)) {
        std::cout << "PDF文件复制成功！" << std::endl;
    } else {
        std::cerr << "PDF文件复制失败。" << std::endl;
    }

    // 复制EXE文件
    if (copyFile(exeSource, exeDestination)) {
        std::cout << "EXE文件复制成功！" << std::endl;
    } else {
        std::cerr << "EXE文件复制失败。" << std::endl;
    }

    return 0;
}
