struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ret;
    int k_th;
    int countNodes(TreeNode* root) {
        if (nullptr == root || -1 != ret) {
            return 0;
        }

        int lc = countNodes(root->left);
        if (lc + 1 == k_th) {
            ret = root->val;
        }
        int lr = countNodes(root->right);
        return lc + 1 + lr;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        k_th = k;
        ret = -1;
        countNodes(root);
        return ret;
    }
};