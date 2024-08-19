struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <math.h>
using namespace std;

class Solution {
public:
    int deepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int l = deepth(root->left);
        int r = deepth(root->right);
        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }

        int l = deepth(root->left);
        int r = deepth(root->right);
        return abs(l - r) < 2;
    }
};