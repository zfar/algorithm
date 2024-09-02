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

        // init
        TreeNode* tmp = root;
        while(nullptr != tmp->left) {
            tmp = tmp->left;
        }
        cur = tmp->val;
        count = 0;
        max_count = -1;
        max_nums.clear();

        // count
        find(root);

        // for last sequence
        if (count > max_count) {
            max_nums.clear();
            max_nums.push_back(cur);
        }
        else if (count == max_count) {
            max_nums.push_back(cur);
        }

        return max_nums;
    }
};

int main() {
    TreeNode n1(1), n2(2);
    n1.right = &n2;
    Solution s;
    s.findMode(&n1);
}