#include <algorithm>
#include <iostream>
#include <iterator>
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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        while (root != nullptr || !s.empty()) {
            if (root != nullptr) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};

int main() {
    auto root = new TreeNode(1);
    // root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    auto vi = sol.inorderTraversal(root);
    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;
    return 0;
}
