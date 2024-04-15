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

    // 1 需要使begin的值为非法值，及begin处的值是可覆盖的; 在整个分拣过程中，
    //   移动end前，要保证begin的值是可覆盖的；
    //   移动begin前，要保证end的值是可覆盖的；
    swap(arr[begin], arr[mid]);
    while (begin < end) {

        // 2.1 应该是 > ，而不是 >=，因为此时arr[begin] 或者是pivote的值（初始状态），或者是小于pivote的值
        for (; end > begin; --end) {

            // 3.1 应该是 < ，而不是 <=;
            // 如果带等于的话，当数组中含有多个与pivote相等的元素时，会出现 这些元素排序错误的问题
            if (arr[end] < pivote) {
                arr[begin] = arr[end];
                break;
            }
        }
        
        // 2.2 同2.1
        for (; begin < end; ++begin) {

            // 3.2 同3.1
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