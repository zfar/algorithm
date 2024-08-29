
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
    // case ok:
    // [1,null,2,3]
    // [1,2,3,4,5,null,null,null,null,7]
    // case failed:
    // [2,null,3,null,1]
    vector<int> postorderTraversal(TreeNode* root) {
        if (nullptr == root) {
            return vector<int>();
        }
        
        stack<TreeNode*> nodes;
        TreeNode* node, *tmp;
        vector<int> ret;

        node = root;
        do {
            while(nullptr != node) {
                nodes.push(node);
                if (nullptr != node->right) {
                    nodes.push(node->right);
                    node->right = nullptr; // !!!
                }
                tmp = node;
                node = node->left;
                tmp->left = nullptr;
            }

            do {
                node = nodes.top();
                if (nullptr != node->left) {
                    tmp = node;
                    node = node->left;
                    tmp->left = nullptr;
                    break;
                }
                if (nullptr != node->right) {
                    tmp = node;
                    node = node->right;
                    tmp->right = nullptr;
                    break;
                }
                nodes.pop();
                ret.push_back(node->val);
            } while (nullptr == node->left && !nodes.empty());
 
        } while(!nodes.empty());

        return ret;
    }
};