#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef union my_ip_addr_
{
    uint32_t ip_num;
    uint8_t ip_byte[4];
} my_ip_addr;

void process_integer_ip(string input, bool isBe) {
    my_ip_addr ip_addr;
    ip_addr.ip_num = atoi(input.c_str());
    if (isBe) {
        cout << ip_addr.ip_byte[0] << "." << ip_addr.ip_byte[1] << "." << ip_addr.ip_byte[2] << "." << ip_addr.ip_byte[3] << endl;
    }
    else {
        cout << ip_addr.ip_byte[3] << "." << ip_addr.ip_byte[2] << "." << ip_addr.ip_byte[1] << "." << ip_addr.ip_byte[0] << endl;
    }
}

void process_string_ip(string& input, bool isBe) {
    my_ip_addr ip_addr;
    int pos = 0, next_pos = 0;
    int index = 0;
    const char* buf = input.c_str();
    for (next_pos = input.find("."); next_pos != string::npos && index < 4; ++index, pos = next_pos + 1, next_pos = input.find(".", pos)) {
        input[next_pos] = 0;
        ip_addr.ip_byte[index] = atoi(buf + pos);
    }

    if (index < 4) {
        ip_addr.ip_byte[index] = atoi(buf + pos);
    }

    if (!isBe) {
        swap(ip_addr.ip_byte[3], ip_addr.ip_byte[0]);
        swap(ip_addr.ip_byte[2], ip_addr.ip_byte[1]);
    }
    
    cout << ip_addr.ip_num << endl;
}

int main() {
    string input;
    int next_pos;

    // check endian mode
    my_ip_addr ip_addr;
    ip_addr.ip_byte[0] = 1;
    bool isBigEndian = true;
    if (ip_addr.ip_num == 1) {
        isBigEndian = false;
    }

    // process the cases
    while( cin >> input ) {
        next_pos = input.find('.');

        // interger to ip
        if (next_pos ==  string::npos) {
            process_integer_ip(input, isBigEndian);
        }
        // ip to interger
        else {
            process_string_ip(input, isBigEndian);
        }
    }

    return 0;
}