#include <iostream>
#include <string>  //string头文件

using namespace std;

#define MAX 1000  // 最大人数

// 通讯录结构体
struct Addressbooks {
    // 通讯录中保存的联系人数组
    struct Person personArray[MAX];
    // 通讯录中当前记录的联系人数量
    int m_Size;
};

// 联系人结构体
struct Person {
    string m_Name;   // 姓名
    int m_Sex;       // 性别：1男2女
    int m_Age;       // 年龄
    string m_Phone;  // 电话
    string m_Addr;   // 地址
};

// 1、添加联系人信息
void addPerson(Addressbooks* abs) {
    if (abs->m_Size == MAX) {
        cout << "通讯录已满，无法添加" << endl;
        return;
    } else {
        cout << "请输入姓名：" << endl;
        string name;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        cout << "请输入性别：" << endl;
        int sex;
        cout << "1——男" << endl;
        cout << "2——女" << endl;
        while (true) {
            cin >> sex;
            if (sex == 1 || sex == 2) {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            } else {
                cout << "输入有误，请重新输入" << endl;
            }
        }

        cout << "请输入年龄：" << endl;
        int age;
        cin >> age;
        abs->personArray[abs->m_Size].m_Age = age;

        cout << "请输入电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        cout << "请输入地址：" << endl;
        string addr;
        cin >> addr;
        abs->personArray[abs->m_Size].m_Addr = addr;

        abs->m_Size++;  // 联系人数量++
        cout << "添加成功！" << endl;
        system("pause");  // 输入任意键继续
        system("cls");    // 清屏
    }
}

// 2、显示所有联系人信息
void showPerson(Addressbooks* abs) {
    if (abs->m_Size == 0) {
        cout << "当前记录为空" << endl;
    } else {
        for (int i = 0; i < abs->m_Size; i++) {
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女")
                 << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Addr << endl;
        }
    }
    system("pause");
    system("cls");
}

// 3、删除指定联系人信息
void deletePerson(Addressbooks* abs) {
    cout << "请输入要删除的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = isExist(*abs, name);
    if (ret != -1) {
        // i < MAX - 1是处理边界情况
        for (int i = ret; i < abs->m_Size && i < MAX - 1; i++) {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_Size--;  // 下标减一
        cout << "删除成功！" << endl;
    } else {
        cout << "查无此人！" << endl;
    }
    system("pause");
    system("cls");
}

// 4、查找指定联系人信息
void findPerson(Addressbooks* abs) {
    cout << "请输入要查找的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = isExist(*abs, name);
    if (ret != -1) {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女")
             << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_Addr << endl;
    } else {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

// 5、修改指定联系人信息
void updatePerson(Addressbooks* abs) {
    cout << "请输入要修改的联系人姓名：" << endl;
    string name;
    cin >> name;
    int ret = isExist(*abs, name);
    if (ret != -1) {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女")
             << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_Addr << endl;

        cout << "请输入修改的姓名：" << endl;
        string pName;
        cin >> pName;
        abs->personArray[ret].m_Name = pName;

        cout << "请输入修改的性别：" << endl;
        cout << "1——男" << endl;
        cout << "2——女" << endl;
        int pSex;
        cin >> pSex;
        while (pSex < 1 || pSex > 2) {
            cout << "输入有误，请重新输入：" << endl;
            cin >> pSex;
        }
        abs->personArray[ret].m_Sex = pSex;

        cout << "请输入修改的年龄：" << endl;
        int pAge;
        cin >> pAge;
        abs->personArray[ret].m_Age = pAge;

        cout << "请输入修改的电话：" << endl;
        string pPhone;
        cin >> pPhone;
        abs->personArray[ret].m_Phone = pPhone;

        cout << "请输入修改的地址：" << endl;
        string pAddr;
        cin >> pAddr;
        abs->personArray[ret].m_Addr = pAddr;

        cout << "修改成功！" << endl;
        system("pause");
        system("cls");
    } else {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

// 6、清空所有联系人
void cleanPerson(Addressbooks* abs) {
    cout << "您确定要清空通讯录吗？" << endl;
    cout << "1、是"
         << "\t"
         << "2、否" << endl;
    int select;
    cin >> select;
    if (select == 1) {
        abs->m_Size = 0;
        cout << "通讯录已清空！" << endl;
    } else {
        cout << "操作已取消!" << endl;
    }
    system("pause");
    system("cls");
}

// 判断是否存在查询的人员，存在返回在数组中索引位置，不存在返回-1
int isExist(Addressbooks abs, string name) {
    for (int i = 0; i < abs.m_Size; i++) {
        if (abs.personArray[i].m_Name == name)
            return i;  // 找到返回下标
    }
    return -1;  // 未找到
}

// 菜单界面
void showMenu() {
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

int main() {
    // 创建通讯录
    Addressbooks abs;
    // 初始化通讯录人数
    abs.m_Size = 0;
    int select = 0;

    while (true) {
        showMenu();

        cin >> select;

        switch (select) {
            case 1:  // 添加联系人
                addPerson(&abs);
                break;
            case 2:  // 显示联系人
                showPerson(&abs);
                break;
            case 3:  // 删除联系人
                deletePerson(&abs);
                break;
            case 4:  // 查找联系人
                findPerson(&abs);
                break;
            case 5:  // 修改联系人
                updatePerson(&abs);
                break;
            case 6:  // 清空联系人
                cleanPerson(&abs);
                break;
            case 0:  // 退出通讯录
                cout << "欢迎下次使用" << endl;
                system("pause");
                return 0;
                break;
            default:
                break;
        }
    }

    system("pause");

    return 0;
}