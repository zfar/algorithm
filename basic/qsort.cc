#include <iostream>
#include <algorithm>
#include <iterator>
using namespace  std;

int get_mid(int* arr, int begin, int end) {
    return begin;
}

int partition(int* arr, int begin, int end) {
    if (begin >= end) return begin;

    int mid = get_mid(arr, begin, end);
    int pivote = arr[mid];
    swap(arr[begin], arr[mid]);
    while (begin < end) {
        for (; end > begin; --end) {
            if (arr[end] < pivote) {
                arr[begin] = arr[end];
                break;
            }
        }
        
        for (; begin < end; ++begin) {
            if (arr[begin] > pivote) {
                arr[end] = arr[begin];
                break;
            }
        }
    }
    arr[begin] = pivote;

    return begin;
}

void quick_sort(int *arr, int begin, int end) {
    if (begin >= end) return;

    int mid = partition(arr, begin, end);
    if (mid - 1 > begin) {
        quick_sort(arr, begin, mid - 1);
    }
    if (mid + 1 < end) {
        quick_sort(arr, mid + 1, end);
    }
}

int main() {
    int a[] = { 3, 1, 4, 2, 5, 8, 6, 7 };
    quick_sort(a, 0, sizeof(a) / sizeof(int) - 1);
    std::copy(std::begin(a), std::end(a), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}