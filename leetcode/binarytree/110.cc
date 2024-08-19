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
        if (l < 0) {
            return -1;
        }

        int r = deepth(root->right);
        if (r < 0) {
            return -1;
        }

        if (abs(l - r) > 1) {
            return -1;
        }

        return max(l, r) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (nullptr == root) {
            return true;
        }
        return deepth(root) > 0 ? true: false;
    }
};