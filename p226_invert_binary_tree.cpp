#include "base/util.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) { 
        if (root == nullptr)
            return root;
        auto right = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(right);
        return root;
    }
};

int main() {
    auto tree = createTree({"4", "2", "7", "1", "3", "6", "9"});
    Solution sol;
    auto res = sol.invertTree(tree);
    print(res);
    destroy(res);
    return 0;
}