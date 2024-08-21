#include<vector>
// #include<pair>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (nullptr == root) {
            return vector<vector<int>>();
        }

        // level traversal
        vector<pair<TreeNode*,int>> nodes;
        nodes.emplace_back(root, 1);
        int it = 0;
        int level;
        TreeNode* cur;
        while (it < nodes.size()) {
            level = nodes.at(it).second;
            cur = nodes.at(it).first;
            if (nullptr != cur->left) {
                nodes.emplace_back(cur->left, level + 1);
            }
            if (nullptr != cur->right) {
                nodes.emplace_back(cur->right, level + 1);
            }
            ++it;
        }

        // pack the result
        vector<vector<int>> ret;
        vector<int> level_ret;
        int node_level, level_size = 0;
        for (int i = nodes.size() - 1; i > -1; --i) {
            node_level = nodes.at(i).second;
            if (node_level == level) {
                ++level_size;
            }
            else {
                for (int j = 1; j < level_size + 1; ++j) {
                    level_ret.emplace_back(nodes.at(i + j).first->val);
                }
                ret.emplace_back(level_ret);
                level_size = 1; // or the top level vector will miss
                --level; // or the one level vector will be broken
                level_ret.clear();
            }
        }

        if (level_size > 0) {
            for(int j = 0; j < level_size; ++j) {
                level_ret.emplace_back(nodes.at(j).first->val);
            }
            ret.emplace_back(level_ret);
        }

        return ret;
    }
};

int main() {
    vector<int> nums;
    size_t c = nums.capacity();
    nums.emplace_back(3);
    c = nums.capacity();
    
    auto it = nums.begin();
    int i = 5;
    while(i--) {
        nums.emplace_back(3+i);
        c = nums.capacity(); // watch the reallocation
    }
    ++it; // reallocation may disable the iterator
    i = *it;
    ++it;
    i = *it;

    return 0;
}