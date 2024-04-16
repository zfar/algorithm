#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int total;
    int num;
    int nums[501];
    while (cin >> total) {
        memset(nums, 0, sizeof(nums));
        while(total--) {
            cin >> num;
            nums[num] =  1;
        }

        for (int i =  1; i < 501; ++i) {
            if (nums[i]) {
                cout << i << endl;
            }
        }
    }
}