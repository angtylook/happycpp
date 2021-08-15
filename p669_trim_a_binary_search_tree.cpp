#include <iostream>
#include "base/util.h"

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) {
            return nullptr;
        }
        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

int main() {
    Solution sol;

    TreeNode n0(0);
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);

    n2.left = &n1;
    n0.right = &n2;
    n3.left = &n0;
    n3.right = &n4;

    auto n = sol.trimBST(&n3, 1, 3);
    print(n);

    return 0;
}
