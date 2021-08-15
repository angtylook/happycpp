#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        auto val = root->val;
        std::stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            if (root != nullptr) {
                if (val != root->val) {
                    return false;
                }
                s.push(root->right);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
            }
        }
        return true;
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(1);

    Solution sol;
    std::cout << sol.isUnivalTree(root) << std::endl;
}
