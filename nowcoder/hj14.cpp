#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    int count;
    string str;
    vector<string> vec;
    while (cin >> count) {
        vec.clear();
        while(count--) {
            cin >> str;
            vec.push_back(str);
        }
        sort(vec.begin(), vec.end());
        copy(vec.begin(), vec.end(), ostream_iterator<string>(cout, "\n"));
    }
    return 0;
}