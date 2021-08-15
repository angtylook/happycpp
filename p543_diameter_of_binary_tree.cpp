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
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        int h = 0;
        diameterOfBinaryTree(root, d, h);
        return d;
    }
    void diameterOfBinaryTree(TreeNode* root, int& diameter, int& height) {
        if (root == nullptr) {
            diameter = 0;
            height = 0;
            return;
        }
        int left_d = 0;
        int left_h = 0;
        int right_d = 0;
        int right_h = 0;
        diameterOfBinaryTree(root->left, left_d, left_h);
        diameterOfBinaryTree(root->right, right_d, right_h);

        height = std::max(left_h, right_h) + 1;
        diameter = std::max(left_d, right_d);
        diameter = std::max(diameter, left_h + right_h);
    }
};

int main() {
    Solution sol;
    auto tree = createTree({"1", "2", "3", "4", "5"});
    std::cout << sol.diameterOfBinaryTree(tree) << std::endl;
    destroy(tree);
    return 0;
}