#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val == val) {
                return root;
            }
            if (root->val < val) {
                root = root->right;
                continue;
            }
            if (root->val > val) {
                root = root->left;
            }
        }
        return root;
    }
};

int main() {
    auto root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    auto node = sol.searchBST(root, 2);
    if (node) {
        std::cout << node->val << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }
    return 0;
}