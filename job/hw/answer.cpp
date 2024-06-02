#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
给定一个数组nums，求对应的数组answer。answer[i] 为 nums除nums[i]之外的
元素的乘积。
要求O(n) 复杂都内完成，且不要使用除法。
例如 nums = {1, 2, 3, 4} 对应的answer数组为 {24, 12, 8, 6}
*/
void get_answer(int *nums, int len) {
    vector<int> prefix;
    vector<int> suffix;

    prefix.push_back(1);
    for (int i = 0; i < len; ++i) {
        // prefix[i + 1] = prefix[i] * nums[i]; // 溢出了！
        prefix.push_back(prefix.back() * nums[i]);
    }

    suffix.push_back(1);
    for (int i = len - 1; i > -1; --i) {
        // suffix[i + 1] = suffix[i] * nums[i]; // 溢出了！
        suffix.push_back(suffix.back() * nums[i]);
    }

    vector<int> answer;
    for (int i = 0; i < len; ++i) {
        answer.push_back(prefix[i] * suffix[len - i - 1]);
    }

    for_each(answer.begin(), answer.end(), [](int a)->void{cout << a << " ";});
}

/*
^  1  2  3  4  $
1  1  2  6  24
1  4  12 24 24
*/
int main() {
    int nums[] = {1, 2, 3, 4};
    get_answer(nums, sizeof(nums) / sizeof(int));
    return 0;
}