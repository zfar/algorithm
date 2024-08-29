
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (nullptr == root) {
            return vector<int>();
        }
        
        stack<TreeNode*> nodes;
        TreeNode* node;
        vector<int> ret;

        node = root;
        while(!nodes.empty()) {
            while(nullptr != node) {
                nodes.push(node);
                if (nullptr != node->right) {
                    nodes.push(node->right);
                }
                node = node->left;
            }

            node = nodes.top();
            nodes.pop();
            ret.push_back(node->val);
        }

        return ret;
    }
};