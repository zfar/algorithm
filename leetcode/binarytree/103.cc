struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (nullptr == root) {
            return vector<vector<int>>();
        }

        deque<TreeNode*> nodes;
        TreeNode* node;
        int size, i;
        bool beginLeft = true;
        vector<vector<int>> ret;

        nodes.push_back(root);
        while(!nodes.empty()) {
            size = nodes.size();
            ret.emplace_back(size);
            if (beginLeft) {
                for (i = 0; i < size; ++i) {
                    node = nodes.front();
                    nodes.pop_front();
                    ret.back()[i] = node->val;
                    if (node->left) {
                        nodes.emplace_back(node->left);
                    }
                    if (node->right) {
                        nodes.emplace_back(node->right);
                    }
                }
                beginLeft = false;
            }
            else {
                auto r_it = nodes.rbegin();
                i = 0;
                for (; r_it != nodes.rend(); ++r_it) {
                    node = *r_it; 
                    ret.back()[i++] = (node->val);
                }

                while (size--) {
                    node = nodes.front();
                    nodes.pop_front();
                    if (node->left) {
                        nodes.emplace_back(node->left);
                    }
                    if (node->right) {
                        nodes.emplace_back(node->right);
                    }
                }
                
                beginLeft = true;
            }
        }

        return ret;
    }
};

#include <iostream>
int main() {
    TreeNode node = {1, nullptr, nullptr};
    Solution s;
    auto seq = s.zigzagLevelOrder(&node);
    vector<vector<int>> ret;
    ret.emplace_back(5); // 匹配vector(size_type count) 构造函数
    cout << ret[0].capacity() << endl;
    cout << ret[0].size() << endl;
    return 0;
}