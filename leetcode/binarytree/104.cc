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

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        queue<TreeNode*> nodes;
        TreeNode* node;
        nodes.push(root);
        int size, level = 0;
        while(! nodes.empty()) {
            size = nodes.size();
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
            ++level;
        }

        return level;
    }
};