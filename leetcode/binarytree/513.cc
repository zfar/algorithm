
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <queue>
using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodes;
        TreeNode* node, *ret;
        nodes.push(root);
        int size;

        while(!nodes.empty()) {
            size = nodes.size();
            ret = nodes.front();

            while(size--) {
                node = nodes.front();
                nodes.pop();
                if (nullptr != node->left) {
                    nodes.push(node->left);
                }
                if (nullptr != node->right) {
                    nodes.push(node->right);
                }
            }
        }

        return ret->val;
    }
};