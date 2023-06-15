#include <fstream>
#include <iostream>

void appendFileTo(const std::string &sourceFile, std::ofstream &outputFile) {
    std::ifstream inputFile(sourceFile, std::ios::binary);
    outputFile << inputFile.rdbuf();
}

int main() {
    std::string pdfFilePath = "resources\\tabulary.pdf"; // PDF文件路径
    std::string exeFilePath = "resources\\geek64.exe"; // EXE文件路径
    std::string outputFilePath = "resources\\output.exe"; // 输出文件路径

    std::ofstream outputFile(outputFilePath, std::ios::binary);

    if (!outputFile) {
        std::cerr << "无法创建输出文件\n";
        return 1;
    }

    appendFileTo(pdfFilePath, outputFile);
    appendFileTo(exeFilePath, outputFile);

    return 0;
}
