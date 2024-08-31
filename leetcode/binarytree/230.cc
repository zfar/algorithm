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
    int count;
    int k_th;
    void countNodes(TreeNode* root) {
        if (nullptr == root || -1 != ret) {
            return;
        }

        countNodes(root->left);
        ++count;
        if (count == k_th) {
            ret = root->val;
            return;
        }
        countNodes(root->right);
        return;
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        ret = -1;
        count = 0;
        k_th = k;
        countNodes(root);
        return ret;
    }
};