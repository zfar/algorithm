#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
using namespace std;

// 输入字符串中只含有 X、Y，且为均衡字符串
// 均衡字符串： XY个数相等
// 求 切分成子串，且子串为均衡字符 后，子串数的最大值
void count_ch(const string& str, int& xn, int& yn, int s, int e) {
    for (; s < e; ++s) {
        if (str[s] == 'X') {
            ++xn;
        }
        else {
            ++yn;
        }
    }
}

// xxyyxyxy
int cut_num(const string& str) {
    int s = 0;
    int step = 2;
    int e;
    int count = 0;
    int xn = 0, yn = 0; 
    int count_index = 0;
    for (e = 2; e < str.size() + 1; e += 2) {
        count_ch(str, xn, yn, count_index, e);
        if (xn == yn) {
            xn = 0;
            yn = 0;
            s = e;
            count_index = e;
            ++count;
        }
        else {
            count_index = e;
        }
    }

    return count;
}

int main() {
    string str;
    while(cin >> str) {
        cout << cut_num(str) << endl;
    }
    return 0;
}