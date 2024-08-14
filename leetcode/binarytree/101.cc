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

class Solution {
public:
    bool isMirror(TreeNode* leftT, TreeNode* rightT) {
        if (nullptr != leftT && nullptr == rightT || nullptr == leftT && nullptr != rightT) {
            return false;
        }

        if (nullptr == leftT && nullptr == rightT) {
            return true;
        }

        if (leftT->val != rightT->val) {
            return false;
        }

        bool ret = isMirror(leftT->left, rightT->right);
        if (!ret) {
            return ret;
        }

        return isMirror(leftT->right, rightT->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};