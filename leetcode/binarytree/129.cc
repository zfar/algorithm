
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int sum;
public:
    void getSum(TreeNode* root, int num) {
        num *= 10;
        num += root->val;

        // ending conditions
        if (nullptr == root->left && nullptr == root->right) {
            sum += num;
            return;
        }

        if (nullptr != root->left) {
            getSum(root->left, num);
        }

        if (nullptr != root->right) {
            getSum(root->right, num);
        }
    }

    int sumNumbers(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int num = 0;
        sum = 0;
        getSum(root, num);
        return sum;
    }
};