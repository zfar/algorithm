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
        auto it = nodes.begin();
        int level;
        while (it != nodes.end())
        {
            level = it->second;
            if (nullptr != it->first->left) {
                nodes.emplace_back(it->first->left, level + 1);
            }
            if (nullptr != it->first->right) {
                nodes.emplace_back(it->first->right, level + 1);
            }
            ++it;
        }

        // pack the result
        vector<vector<int>> ret;
        vector<int> level_ret;
        int node_level;
        for (auto r_it = nodes.rbegin(); r_it != nodes.rend(); ++r_it) {
            node_level = r_it->second;
            if (node_level == level) {
                level_ret.emplace_back(r_it->first->val);
            }
            else {
                ret.emplace_back(level_ret);
                level_ret.clear();
            }
        }

        if (!level_ret.empty()) {
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