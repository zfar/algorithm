#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string str;
    int8_t table[128];
    int len;
    int chr;
    int count;
    while(cin >> str) {
        memset(table, 0, sizeof(table));
        count = 0;
        len = str.size();
        for (int i = 0; i < len; ++i) {
            chr = str[i];
            if (chr < 0 || chr > 127) {
                continue;
            }

            table[chr] = 1;
        }

        for (int i = 0; i < 128; ++i) {
            if (table[i]) {
                ++count;
            }
        }
        cout << count << endl;

    }

    return 0;
}