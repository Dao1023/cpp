// my_calc7.0
// by gj
// 增添指数为整数的幂运算
// 新增一些小优化

#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
#include <cmath>
#include <vector>
#define x first
#define y second
using namespace std;
const int N = 1e5;

typedef pair<string, string> PSS;

string h_add(string a, string b);
string h_sub(string a, string b);
string h_mul(string a, string b);
string h_div(string a, string b);

map<char, int> h = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
stack<PSS> nums;
stack<char> op;
string s;
bool div_0 = false;
bool pow_flag = false;
PSS add(PSS a, PSS b){
    return {h_add(a.x, b.x), h_add(a.y, b.y)};
}

PSS sub(PSS a, PSS b){
    return {h_sub(a.x, b.x), h_sub(a.y, b.y)};
}

PSS mul(PSS a, PSS b){
    return {h_sub(h_mul(a.x, b.x), h_mul(a.y, b.y)), h_add(h_mul(a.x, b.y), h_mul(a.y, b.x))};
}

PSS div(PSS a, PSS b){
    string aa = h_add(h_mul(a.x, b.x), h_mul(a.y, b.y));
    string bb = h_add(h_mul(b.x, b.x), h_mul(b.y, b.y));
    string cc = h_sub(h_mul(a.y, b.x), h_mul(a.x, b.y));
    string dd = h_add(h_mul(b.x, b.x), h_mul(b.y, b.y));
    return {h_div(aa, bb), h_div(cc, dd)}; 
} 


PSS Pow(PSS a, PSS b){
    if(b.x == "0") return {"1", "0"};
    long long p = 0;
    for(int i = 0; i < b.x.size(); i ++){
        p = p * 10 + b.x[i] - '0';
    }
    PSS res = {"1", "0"};
    while(p){
        if(p & 1) res = mul(res, a);
        a = mul(a, a);
        p >>= 1;
    }
    return res;
}

bool check_len(vector<int> a, vector<int> b){
    if(a.size() != b.size()) return a.size() > b.size();
    for(int i = 0; i < a.size(); i ++) {
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}

bool check_decimal(string a){
    for(int i = 0; i < a.size(); i ++) if(a[i] == '.') return true;
    return false;
}


bool check_pow(PSS a){
    if(check_decimal(a.x) || a.y != "0") {
        pow_flag = true;
        return false;
    }
    return true;
}

bool check_op(char a){
    if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^') return true;
    else return false;
}

bool check_top(){
    return nums.size() >= 2; 
}

string del_lzero(string a){
    if(a.size() <= 1 || a[0] != '0') return a;
    if(a[0] == '0' && a[1] == '.') return a;
    if(check_decimal(a)){
        int j = 0;
        while(a[j] == '0' && a[j + 1] != '.') j ++;
        return a.substr(j, a.size() - j);
    } else {
        int j = 0;
        while(j < a.size() - 1 && a[j] == '0') j ++;
        return a.substr(j, a.size() - j);
    }
}

string del_rzero(string a){
    if(!check_decimal(a)) return a;
    int i;
    for(i = a.size() - 1; a[i] == '0'; i --);
    if(a[i] == '.') i --;
    return a.substr(0, i + 1);
}


string h_add(string a, string b){
    string res;
    int sign_a = 1, sign_b = 1;
    if(a[0] == '-') a = a.substr(1, a.size() - 1), sign_a = -1;
    if(b[0] == '-') b = b.substr(1, b.size() - 1), sign_b = -1;
    
    if (sign_a == 1 && sign_b == -1) return h_sub(a, b);
    else if (sign_a == -1 && sign_b == 1) return h_sub(b, a);
    else if (sign_a == -1 && sign_b == -1) return ('-' + h_add(a, b));
    
    vector<int> lnum_a, rnum_a, lnum_b, rnum_b, lans, rans;
    int a_idx_decimal = -1, b_idx_decimal = -1;
    

    for(int i = 0; i < a.size(); i ++){
        if(a[i] == '.'){
            a_idx_decimal = i + 1;
            break;
        }
        lnum_a.push_back(a[i] - '0');
    }
    reverse(lnum_a.begin(), lnum_a.end());
    for(int i = 0; i < b.size(); i ++){
        if(b[i] == '.'){
            b_idx_decimal = i + 1;
            break;
        }
        lnum_b.push_back(b[i] - '0');
    }
    reverse(lnum_b.begin(), lnum_b.end());
    if(a_idx_decimal != -1) {
        for(int i = a_idx_decimal; i < a.size(); i ++){
            rnum_a.push_back(a[i] - '0');
        }
    }
    if(b_idx_decimal != -1){
        for(int i = b_idx_decimal; i < b.size(); i ++){
            rnum_b.push_back(b[i] - '0');
        }
    }
    int t = 0;
    for(int i = 0; i < lnum_a.size() || i < lnum_b.size(); i ++){
        if(i < lnum_a.size()) t += lnum_a[i];
        if(i < lnum_b.size()) t += lnum_b[i];
        lans.push_back(t % 10);
        t /= 10;
    }
    if(t) lans.push_back(1);
    while(lans.size() > 1 && lans.back() == 0) lans.pop_back();
    t = 0;
    for(int i = max(rnum_a.size(), rnum_b.size()) - 1; i >= 0; i --){
        if(i < rnum_a.size()) t += rnum_a[i];
        if(i < rnum_b.size()) t += rnum_b[i];
        rans.push_back(t % 10);
        t /= 10;
    }
    // 整数部分化为字符串
    reverse(rans.begin(), rans.end());
    while(rans.size() && rans.back() == 0) rans.pop_back();
    for(int i = lans.size() - 1; i >= 0; i --) res += lans[i] + '0';
    if(rans.size()){
        res += '.';
        for(int i = 0; i < rans.size(); i ++) res += rans[i] + '0';  
    }
    if(t) res = h_add(res, "1");
    return res;
}

string h_sub(string a, string b){
    string res;
    int sign_a = 1, sign_b = 1;
    if(a[0] == '-') a = a.substr(1, a.size() - 1), sign_a = -1;
    if(b[0] == '-') b = b.substr(1, b.size() - 1), sign_b = -1;

    if(sign_a == -1 && sign_b == 1) return '-' + h_add(a, b);
    else if(sign_a == 1 && sign_b == -1) return h_add(a, b);
    else if(sign_a == -1 && sign_b == -1) return h_sub(b, a);

    vector<int> lnum_a, rnum_a, lnum_b, rnum_b, lans, rans;
    int a_idx_decimal = -1, b_idx_decimal = -1;

    for(int i = 0; i < a.size(); i ++){
        if(a[i] == '.'){
            a_idx_decimal = i + 1;
            break;
        }
        lnum_a.push_back(a[i] - '0');
    }
    reverse(lnum_a.begin(), lnum_a.end());
    for(int i = 0; i < b.size(); i ++){
        if(b[i] == '.'){
            b_idx_decimal = i + 1;
            break;
        }
        lnum_b.push_back(b[i] - '0');
    }
    reverse(lnum_b.begin(), lnum_b.end());
    if(a_idx_decimal != -1) {
        for(int i = a_idx_decimal; i < a.size(); i ++){
            rnum_a.push_back(a[i] - '0');
        }
    }
    if(b_idx_decimal != -1){
        for(int i = b_idx_decimal; i < b.size(); i ++){
            rnum_b.push_back(b[i] - '0');
        }
    }

    if(!check_len(lnum_a, lnum_b)) {
        res = '-' + h_sub(b, a);
        return res;
    }
    int t = 0;
    for(int i = 0; i < lnum_a.size(); i ++) {
        t = lnum_a[i] - t;
        if(i < lnum_b.size()) t -= lnum_b[i];
        lans.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while(lans.size() > 1 && lans.back() == 0) lans.pop_back();
    t = 0;
    for(int i = max(rnum_a.size(), rnum_b.size()); i >= 0; i --){
        if(i >= rnum_a.size()) t = 0 - t;
        else t = rnum_a[i] - t;
        if(i < rnum_b.size()) t -= rnum_b[i];
        rans.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }

    reverse(rans.begin(), rans.end());
    while(rans.size() && rans.back() == 0) rans.pop_back();

    for(int i = lans.size() - 1; i >= 0; i --) res += (lans[i] + '0');
    if(rans.size()){
        res += '.';
        for(int i = 0; i < rans.size(); i ++) res += rans[i] + '0';
    }
    if(t) res = h_sub(res, "1");

    return res;

}

string h_mul(string a, string b){
    string res;
    int sign_a = 1, sign_b = 1;
    if(a[0] == '-') {
        a = a.substr(1, a.size() - 1);
        sign_a = -1;
    }
    if(b[0] == '-') {
        b = b.substr(1, b.size() - 1);
        sign_b = -1;
    }
    if(sign_a + sign_b == 0) {
        res += '-';
        res += h_mul(a, b);
        return res;
    } 

    vector<int> num_a, num_b;
    int a_idx_decimal = -1, b_idx_decimal = -1;

    for(int i = 0; i < a.size(); i ++){
        if(a[i] == '.'){
            a_idx_decimal = i + 1;
            continue;
        }
        num_a.push_back(a[i] - '0');
    }
    // 去除小数后导0
    if(a_idx_decimal != -1) {
        int len = a.size() - a_idx_decimal;
        while(len && num_a.back() == 0) num_a.pop_back(), len --;
        if(!len) a_idx_decimal = -1;
    }
    reverse(num_a.begin(), num_a.end());
    for(int i = 0; i < b.size(); i ++){
        if(b[i] == '.'){
            b_idx_decimal = i + 1;
            continue;
        }
        num_b.push_back(b[i] - '0');
    }
    // 去除小数后导0
    if(b_idx_decimal != -1) {
        int len = b.size() - b_idx_decimal;
        while(len && num_b.back() == 0) num_b.pop_back(), len --;
        if(!len) b_idx_decimal = -1;
    }
    reverse(num_b.begin(), num_b.end());

    vector<int> ans(num_a.size() + num_b.size() + 5, 0);
    // 看作整数乘积
    for(int i = 0; i < num_a.size(); i ++){
        for(int j = 0; j < num_b.size(); j ++){
            ans[i + j] += num_a[i] * num_b[j];
        }
    }
    for(int i = 0; i < ans.size(); i ++){
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
    reverse(ans.begin(), ans.end());
    // 小数有几位
    int len_a = 0, len_b = 0;
    if(a_idx_decimal != -1) len_a = num_a.size() - a_idx_decimal + 1;
    if(b_idx_decimal != -1) len_b = num_b.size() - b_idx_decimal + 1;
    
    int j = len_a + len_b;
    // 去除答案小数后导0
    while(j){
        if(ans.back() == 0) ans.pop_back();
        else break;
        j --;
    }
    // 不需要往前补0
    if(j < ans.size()){
        for(int i = 0; i < ans.size(); i ++){
            if(i == ans.size() - j) res += '.';
            res += ans[i] + '0';
        }
    }else{
        res += "0.";
        for(int i = 0; i < j - ans.size(); i ++) res += '0';
        for(auto i : ans) res += i + '0';
    }
    return res;
}

string h_div(string a, string b){
    string res;
    int sign_a = 1, sign_b = 1;
    if(a[0] == '-') a = a.substr(1, a.size() - 1), sign_a = -1;
    if(b[0] == '-') b = b.substr(1, b.size() - 1), sign_b = -1;

    double c = 0, d = 0, t = 10;
    bool a_is_dml = false, b_is_dml = false;
    for(int i = 0; i < a.size(); i ++){
        if(a[i] == '.') {
            a_is_dml = true;
            continue;
        }
        if(!a_is_dml){
            c = c * 10 + a[i] - '0';
        }else {
            c = c + (a[i] - '0') / t;
            t *= 10;
        }
    }
    t = 10;
    for(int i = 0; i < b.size(); i ++){
        if(b[i] == '.') {
            b_is_dml = true;
            continue;
        }
        if(!b_is_dml){
            d = d * 10 + b[i] - '0';
        }else {
            d = d + (b[i] - '0') / t;
            t *= 10;
        }
    }
    if(sign_a * sign_b == 1) t = c / d;
    else t = c / d * (-1);
    
    char tmp[N];
    sprintf(tmp, "%lf", t);
    int i;
    for(i = 0; tmp[i]; i ++) res += tmp[i];
    return res;
}

PSS del_back(PSS a){
    a.x = del_lzero(a.x);
    a.x = del_rzero(a.x);
    a.y = del_lzero(a.y);
    a.y = del_rzero(a.y);
    return {a.x, a.y};
}

bool eval(){
    auto a = nums.top();
    nums.pop();
    auto b = nums.top();
    nums.pop();
    char t = op.top();
    if(t == '+') nums.push(add(a, b));
    else if(t == '-') nums.push(sub(b, a));
    else if(t == '*') nums.push(mul(b, a));
    else if(t == '/') {
        if (a.x == "0" && a.y == "0") {
            div_0 = true;
            return false;
        } 
        nums.push(div(b, a));
    }else if(t == '^') {
        if(!check_pow(a)) return false;
        if(a.x[0] == '-') {
            a = {a.x.substr(1, a.x.size() - 1), a.y};
            nums.push(div({"1", "0"}, Pow(b, a)));
        }else nums.push(Pow(b, a));
    }else if(t == '(') {
        nums.push(b);
        nums.push(a);
    }
    op.pop();
    return true;
}

PSS get_num(int &j){
    string a;
    bool isdecimal = false, iscomplex = false;
    while(j < s.size() && (isdigit(s[j]) || s[j] == '.' || s[j] == 'i')){
        if(!isdecimal && s[j] == '.') {
            a += '.';
            j ++;
            isdecimal = true;
            continue;
        }
        if(s[j] == 'i') {
            iscomplex = true;
            j ++;
            break;
        }
        if(isdigit(s[j])) a += s[j];
        else break;
        j ++;
    }
    a = del_lzero(a);
    a = del_rzero(a);
    if(iscomplex) {
        return {"0", a};
    }else return {a, "0"};
}

bool work(){
    int cnt_left = 0, cnt_right = 0;
    for(int i = 0; i < s.size(); i ++){
        if(isdigit(s[i])){
            PSS numb = get_num(i);
            nums.push(numb);
            i --;
        } else if (s[i] == '('){
            if(i >= 1 && s[i - 1] == ')') op.push('*');
            op.push('(');
            cnt_left ++;
        } else if (s[i] == ')'){
            cnt_right ++;
            if(cnt_left >= cnt_right && (s[i - 1] == 'i' || isdigit(s[i - 1]))) {
                while(op.top() != '(') {
                    if(!eval()) return false;
                }
                op.pop();
            }else return false;
        } else if (check_op(s[i])){
            if(i == 0 && s[i] == '-' || i >= 1 && s[i] == '-' && s[i - 1] == '(') {
                nums.push({"-1", "0"});
                op.push('*');
                continue;
            }
            if(i >= 1 && (s[i - 1] == 'i' || isdigit(s[i - 1]) || s[i - 1] == ')')){
                while(op.size() && h[s[i]] <= h[op.top()]) {
                    if(!eval()) return false;
                }
                op.push(s[i]);
            }else {
                return false;
            }
        }else return false;
    }
    while(!op.empty() && check_top()) {
        if(!eval()) return false;
    }
    return true;
}


int main(){
    while(true){
        while(nums.size()) nums.pop();
        while(op.size()) op.pop();
        cout << "输入一个表达式" << endl;
        cin >> s;
        if(work()){
            auto t = nums.top();
            t = del_back(t);
            if(t.y != "0") {
                if(t.x != "0") cout << t.x;
                if(t.y[0] != '-') cout << '+';
                if(t.y != "1" || t.y != "-1") cout << t.y;
                if(t.y == "-1") cout << '-';
                cout << 'i' << endl;
            }else{
                cout << t.x << endl;
            }
            break;
        }else {
            if(div_0) {
                cout << "不能除以0" << endl;
                div_0 = false;
            } else if(pow_flag) {
                cout << "暂不支持指数为小数(复数)" << endl;
                pow_flag = false;
            } else {
                cout << "表达式错误" << endl;
            }
        }
    }
    return 0;
}