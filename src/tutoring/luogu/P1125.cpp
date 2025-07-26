#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    // 统计字符串每个字符的数量
    int count[26] = {0};
    for (char c : s) {
        count[c - 'a']++;
    }

    // 输出出现次数最多的字符及其出现次数
    int max_count = 0;
    int min_count = 100;
    for (int i = 0; i < 26; i++) {
        if (count[i] > max_count) max_count = count[i];
        if (count[i] < min_count && count[i]) min_count = count[i];
    }

    // 检测是否为质数
    int d = max_count - min_count;
    for (int i = 2; i <= d; i++) {
        if (d % i == 0) {
            cout << "Lucky Word" << endl;
            cout << d;
            return 0;
        }
    }
    cout << "No Answer" << endl;
    cout << 0;

    return 0;
}