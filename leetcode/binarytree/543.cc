struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<math.h>
using namespace std;

class Solution {
    int max_d;
    int countDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int ld = countDepth(root->left);
        int rd = countDepth(root->right);
        int d = ld + rd;
        if (d > max_d) {
            max_d = d;
        }

        return max(ld, rd) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        max_d = 0;
        countDepth(root);
        return max_d;
    }
};