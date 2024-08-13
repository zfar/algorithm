/**
 * Definition for a binary tree node.
 */

#include <vector>
using namespace std;

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
    vector<int> values;
    bool isValidBST(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }

        if (nullptr != root->left && root->left->val >= root->val) {
            return false;
        }
        if (nullptr != root->right && root->right->val <= root->val) {
            return false;
        }

        bool ret = isValidBST(root->left);
        if (! ret) {
            return ret;
        }
        if (! values.empty() && values.back() >= root->val) {
            ret = false;
        }

        values.emplace_back(root->val);

        ret = isValidBST(root->right);
        if (! ret) {
            return ret;
        }
        if (! values.empty() && values.back() <= root->val ) {
            return false;
        }

        return true;
    }
};