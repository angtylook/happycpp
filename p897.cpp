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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) {
            return root;
        }
        root->right = increasingBST(root->right);
        auto left = increasingBST(root->left);
        root->left = nullptr;
        if (left) {
            auto temp = left;
            while (temp->right) {
                temp = temp->right;
            }
            temp->right = root;
            root = left;
        }
        return root;
    }
};

int main() {
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);
    TreeNode node9(9);

    node5.left = &node3;
    node5.right = &node6;
    node3.left = &node2;
    node3.right = &node4;
    node2.left = &node1;

    node6.right = &node8;
    node8.left = &node7;
    node8.right = &node9;

    Solution sol;
    auto node = sol.increasingBST(&node5);
    while (node) {
        std::cout << node->val << std::endl;
        node = node->right;
    }
    return 0;
}
