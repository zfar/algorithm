struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include<vector>
using namespace std;

class Solution {
    int cur, count;
    int max_count;
    vector<int> max_nums;

    void find(TreeNode* root) {
        if (nullptr == root) {
            return;
        }

        find(root->left);

        // process node
        if (cur == root->val) {
            ++count;
        }
        else {
            if (count > max_count) {
                max_nums.clear();
                max_nums.push_back(cur);
            }
            else if (count == max_count) {
                max_nums.push_back(cur);
            }
            else {
                // do nothing!
            }
            cur = root->val;
            count = 1;
        }

        find(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        cur = -1;
        count = 0;
        max_count = -1;
        max_nums.clear();

        find(root);
        return max_nums;
    }
};