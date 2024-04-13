#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

void bubble_sort(int a[], int n) {
    bool flag = false;
    for (int i = n - 1; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                flag = true;
            }
        }

        if (!flag) {
            break;
        }
    }
}

int main() {
    int a[] = { 3, 1, 4, 2, 5, 8, 6, 7 };
    bubble_sort(a, 8);
    std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}