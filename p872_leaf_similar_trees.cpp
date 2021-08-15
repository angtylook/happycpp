#include <iostream>
#include <stack>
#include <vector>
#include "base/util.h"

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto v1 = dfs(root1);
        std::cout << v1 << std::endl;
        auto v2 = dfs(root2);
        std::cout << v2 << std::endl;
        return v1 == v2;
    }

    std::vector<int> dfs(TreeNode* root) {
        std::vector<int> v;
        std::stack<TreeNode*> s;
        while (root) {
            while (root->left) {
                s.push(root);
                root = root->left;
            }
            if (root->right == nullptr) {
                v.push_back(root->val);
                if (s.empty()) {
                    break;
                }
                root = s.top();
                s.pop();
                while (root->right == nullptr && !s.empty()) {
                    root = s.top();
                    s.pop();
                }
            }
            root = root->right;
        }
        return v;
    }
};

int main() {
    TreeNode n102(102);
    TreeNode n39(39);
    n39.left = &n102;

    TreeNode n62(62);
    n62.right = &n39;

    TreeNode n99(99);
    TreeNode n114(114);
    TreeNode n78(78);
    n78.left = &n99;
    n78.right = &n114;

    TreeNode n71(71);
    n71.left = &n78;

    TreeNode n88(88);
    n88.left = &n62;
    n88.right = &n71;

    TreeNode n116(116);
    TreeNode n64(64);
    TreeNode n46(46);
    n46.left = &n116;
    n46.right = &n64;

    TreeNode n43(43);
    TreeNode n18(18);
    n18.left = &n46;
    n18.right = &n43;

    TreeNode n5(5);
    TreeNode n123(123);
    n123.right = &n5;
    TreeNode n54(54);
    n54.left = &n18;
    n54.right = &n123;

    TreeNode n67(67);
    n67.left = &n88;
    n67.right = &n54;

    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    TreeNode t7(7);
    TreeNode t8(8);
    TreeNode t9(9);

    t5.left = &t6;
    t5.right = &t7;

    t2.left = &t9;
    t2.right = &t8;

    t1.left = &t4;
    t1.right = &t2;

    t3.left = &t5;
    t3.right = &t1;

    Solution sol;
    std::cout << sol.leafSimilar(&n67, &t3) << std::endl;
    return 0;
}
