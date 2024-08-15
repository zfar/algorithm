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
#include <list>
using namespace std;

// 看官方题解，可以不用level这个变量
class Solution {
public:
    using z_pair = pair<TreeNode*, int>; // using
    using z_queue = list<z_pair>;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if (nullptr == root) {
            return vector<vector<int>>();
        }
        z_queue nodes {make_pair(root, 1)}; // 列表初始化
        int level = 1;
        vector<vector<int>> ret;
        vector<int> values;
        while (!nodes.empty()) {
            z_pair node = nodes.front();
            TreeNode* t_node = node.first;
            int node_level = node.second;

            if (node.second != level) {
                ret.emplace_back(values);
                values.clear();
                level += 1;
            }
            values.emplace_back(t_node->val);

            if (nullptr != t_node->left) {
                nodes.emplace_back(make_pair(t_node->left, node_level + 1));
            }
            if (nullptr != t_node->right) {
                nodes.emplace_back(make_pair(t_node->right, node_level + 1));
            }

            nodes.pop_front();
        }

        if (!values.empty()) {
            ret.emplace_back(values);
        }

        return ret;
    }
};