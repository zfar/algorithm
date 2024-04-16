#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main() {
    string ops;
    const char* ops_ptr;
    int x, y;
    int x_weight, y_weight;
    int num;
    int pos, next_pos;
    int sub_len;
    while ( cin >> ops ) {
        x = 0;
        y = 0;
        pos = 0;
        ops_ptr = ops.c_str();
        for (next_pos = ops.find(';', pos);
             next_pos != string::npos;
             pos = next_pos + 1, next_pos = ops.find(';', pos)) {
                sub_len = next_pos - pos;
                if (sub_len < 2 || sub_len > 3) {
                    continue;
                }
                if (!isdigit(ops[pos + 1])) {
                    continue;
                } 
                if (sub_len > 2 && !isdigit(ops[pos + 2])) {
                    continue;
                }

                ops[next_pos] = 0;
                num = atoi(ops_ptr + pos + 1);
                switch (ops[pos]) {
                case 'A':
                    x += -1 * num;
                    break;
                case 'D':
                    x += num;
                    break;
                case 'S':
                    y += -1 * num;
                    break;
                case 'W':
                    y += num;
                    break;
                }
        }

        cout << x << "," << y << endl;
    }
    return 0;
}