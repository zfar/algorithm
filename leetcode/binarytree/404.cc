
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
    bool isLeafNode(TreeNode *n) {
        return nullptr == n->left && nullptr == n->right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        if (nullptr == root->left && nullptr == root->right) {
            return 0;
        }

        // left subtree
        int leftSum = 0; // for empty left subtree, the sum is 0
        if (nullptr != root->left) {
            if (isLeafNode(root->left)) {
                leftSum = root->left->val;
            }
            else {
                leftSum = sumOfLeftLeaves(root->left);
            }
        }

        // right subtree
        int rightSum = sumOfLeftLeaves(root->right);
        return leftSum + rightSum;
    }
};