#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void perm(int* arr, int pos, int len) {
    if (pos == len - 1) {
        std::copy(arr, arr + len, std::ostream_iterator<int>(std::cout, " "));
        std::cout << endl;
    }

    for (int i = pos; i < len; ++i) {
        swap(arr[pos], arr[i]);
        perm(arr, pos + 1, len);
        swap(arr[pos], arr[i]);
    }
}

int main() {
    int a[] = { 3, 1, 2 };
    perm(a, 0, sizeof(a) / sizeof(int));
    return 0;
}