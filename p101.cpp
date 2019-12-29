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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isIdentity(root->left, root->right);
    }

    bool isIdentity(TreeNode* l, TreeNode* r) {
        if (l == nullptr) {
            return r == nullptr;
        }
        if (r == nullptr) {
            return l == nullptr;
        }
        return l->val == r->val && isIdentity(l->left, r->right) && isIdentity(l->right, r->left);
    }
};

int main() {
    Solution sol;
    auto t1 = createTree({"1", "2", "2", "3", "4", "4", "3"});
    std::cout << sol.isSymmetric(t1) << std::endl;
    destroy(t1);

    auto t2 = createTree({"1", "2", "2", "null", "3", "null", "3"});
    std::cout << sol.isSymmetric(t2) << std::endl;
    destroy(t2);
    return 0;
}