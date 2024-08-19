/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // end 不能作为开区间，因为递归调用式的end参数选 (mid - 1) 更直观
    TreeNode* buildBST(vector<int>& nums, int begin, int end) {
        if (begin > end) {
            return nullptr;
        }

        TreeNode* root = new TreeNode();
        int mid = (begin + end) / 2;
        root->val = nums.at(mid);
        root->left = buildBST(nums, begin, mid - 1);
        root->right = buildBST(nums, mid + 1, end);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};

int main() {
    vector<int> nums = {1, 3};
    Solution s;
    TreeNode* t = s.sortedArrayToBST(nums); 
    return 0;
}