#include <iostream>
using namespace std;

int trans(const string& hex) {
    int len = hex.size();
    int weight = 1;
    int ret = 0;
    char digit;
    int digit_num;
    for (int i = len-1; i > 1; --i, weight = weight * 10) {
        digit = hex[i];
        if ( digit < '9') {
            digit_num = digit - '0';
        }
        else {
            digit_num = digit - 'A';
        }

        ret += digit_num * weight;
    }

    return ret;
}

int main() {
    string hex;
    while (cin >> hex) {
        cout << trans(hex) << endl;
    }
}