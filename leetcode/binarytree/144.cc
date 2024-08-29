
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (nullptr == root) {
            return vector<int>();
        }

        stack<TreeNode*> nodes;
        TreeNode *node;
        nodes.push(root);
        vector<int> ret;
        while(!nodes.empty()) {
            node = nodes.top();
            nodes.pop();
            do {
                ret.emplace_back(node);
                if (nullptr != node->right) {
                    nodes.push(node->right);
                }
                node = node->left;
            } while(nullptr != node);
        }

        return ret;
    }
};