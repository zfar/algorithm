struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int lv, gv;
    TreeNode* find(TreeNode* root) {
        int rv = root->val;
        if (lv == rv || gv == rv || (rv > lv && rv < gv)) {
            return root;
        }

        if (gv < rv) {
            return find(root->left);
        }

        if (lv > rv) {
            return find(root->right);
        }

        return nullptr;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!(root && p && q)) {
            return nullptr;
        }

        lv = p->val;
        gv = q->val;
        if (lv > gv) {
            int tmp = lv;
            lv = gv;
            gv = tmp;
        }

        return find(root);
    }
};