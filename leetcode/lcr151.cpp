#include <vector>
using namespace std;

/**
 * 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

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
    vector<vector<int>> decorateRecord(TreeNode* root) {
        vector<vector<int>> ret;
        if (nullptr == root) {
            return ret;
        }
        vector<pair<int, TreeNode*>> vec_nodes;
        vector<int> level_pos;
        vec_nodes.push_back(make_pair(0,root));
        level_pos.push_back(0);
        int i = 0;
        int cur_level = 0;
        while(i < vec_nodes.size()) {
            auto node_info = vec_nodes.at(i);
            if (node_info.first != cur_level) {
                level_pos.push_back(i);
                ++cur_level;
            }
            if (node_info.second->left != nullptr) {
                vec_nodes.push_back(make_pair(cur_level + 1, node_info.second->left));
            }
            if (node_info.second->right != nullptr) {
                vec_nodes.push_back(make_pair(cur_level + 1, node_info.second->right));
            }
            ++i;
        }
        level_pos.push_back(vec_nodes.size());

        int flag = 1;
        for (int i = 0; i < level_pos.size() - 1; ++i) {
            vector<int> level;
            if (flag) {
                for (int j = level_pos[i]; j < level_pos[i + 1]; ++j) {
                    level.push_back(vec_nodes[j].second->val);
                }
            }
            else {
                for (int j = level_pos[i + 1] - 1; j > level_pos[i] - 1; --j) {
                    level.push_back(vec_nodes[j].second->val);
                }
            }
            ret.push_back(level);
            flag ^= 1;
        }

        return ret;
    }
};