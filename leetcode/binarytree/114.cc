
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

class Solution {
private:
    vector<TreeNode*> nodes; 

    void getPreorderNodes(TreeNode* root) {
        if (nullptr == root) {
            return;
        }

        nodes.push_back(root);
        getPreorderNodes(root->left);
        getPreorderNodes(root->right);
    }

    void pack_list() {
        int size = nodes.size();
        TreeNode* cur;
        int i;
        for (i = 0; i < size - 1; ++i) {
            cur = nodes.at(i);
            cur->left = nullptr;
            cur->right = nodes.at(i+1);
        }
        nodes.at(i)->left = nullptr;
        nodes.at(i)->right = nullptr;
    }

public:
    void flatten(TreeNode* root) {
        if (nullptr == root) {
            return;
        }

        nodes.clear();
        getPreorderNodes(root);
        pack_list();
    }
};