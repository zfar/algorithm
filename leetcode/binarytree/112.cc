
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (nullptr == root) {
            return targetSum == 0;
        }

        int subSum = targetSum - root->val;
        bool ret = hasPathSum(root->left, subSum);
        if (ret) {
            return ret;
        }
        
        return hasPathSum(root->right, subSum);
    }
};