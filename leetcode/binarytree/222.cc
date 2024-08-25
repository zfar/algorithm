#include<vector>
using namespace std;

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
    int countNodes(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        int ret;
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int i = 0;
        TreeNode* node;
        while(i < nodes.size()) {
            node = nodes.at(i);
            if (nullptr == node->right) {
                if (nullptr == node->left) {
                    ret = (nodes.size() - 1) * 2 + 1;
                }
                else {
                    ret = nodes.size() * 2;
                }
                break;
            }

            nodes.push_back(node->left);
            nodes.push_back(node->right);
            ++i;
        }

        return ret;
    }
};