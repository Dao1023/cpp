#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 数组是连续的相同类型数据，静态数组
    // int a[5];  // 4B
    // cout << a << endl;
    // cout << &a[0] << endl;
    // cout << &a[1] << endl;
    // cout << &a[2] << endl;
    // int a[5] = {0};

    // 动态数组
    vector<int> v1;
    vector<int> v2(5);
    vector<int> v3(5, 3);
    vector<int> v4 = {1, 2 ,3};

    // vector<int> v = {1,2,3,4,5};
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    // cout << v[4] << endl;
    // cout << v[5] << endl;
    // cout << v.at(5) << endl;   // 有提醒越界功能
    // cout << v.front() << endl;
    // cout << v.back() << endl;

    v.push_back(10);   // push 单词：推、放入，反义词 pull：拉
    // v.pop_back();    // pop 单词：弹出
    v.insert(v.begin() + 5, 15);    // 插入是插在别人的前面
    v.erase(v.begin() + 6);
    // v.clear();


    // // 索引 v[i]
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // };
    // cout << endl;
    // // 迭代器，用 != 更高效和安全，需要 GCC 11
    // for (auto it = v.begin(); it != v.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    // // for 循环
    // for (int value : v) {
    //     cout << value << " ";
    // }
    // cout << endl;

    // cout << v.size() << endl;       // 多少个元素 6
    // cout << v.capacity() << endl;   // 占多少内存 8
    // v.resize(10, 100);              // 6→10 8→12
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;
    // v.resize(3);                    // 10→3 12→12
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;
    // v.reserve(3);                  // 3→3 12→12
    // cout << v.size() << endl;
    // cout << v.capacity() << endl;

    int* p = v.data();
    // cout << p << " " << *p << endl;
    // cout << p+1 << " " << *(p+1) << endl;


    // int n;
    // std::cout << "请输入元素的数量: ";
    // std::cin >> n;

    // std::vector<int> vec(n);

    // std::cout << "请输入 " << n << " 个整数: ";
    // for(int i = 0; i < n; i++) {
    //     std::cin >> vec[i];
    // }

    // std::cout << "您输入的数组是: ";
    // for(int i = 0; i < n; i++) {
    //     std::cout << vec[i] << " ";
    // }
    // std::cout << std::endl;


    int a[5][5];
    // vector<数据类型>
    // >>> a = [[1,2,3],[4,5,6],[7,8,9]]
    // >>> a[1]
    // [4, 5, 6]
    // >>> a[1][2]
    // 6

    // vector<vector<int>> vec;
    vector<vector<int>> vec(3, vector<int>(2, 1));
    vec.push_back(vector<int>(2, 10));
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 2; j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}