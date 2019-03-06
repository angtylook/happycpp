#include <iostream>
#include "base/util.h"

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) { return nullptr; }
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

    print(&n3);

    auto tree = createTree(std::vector<std::string>{"3", "0", "4", "null", "2",
                                                    "null", "null", "1", "null",
                                                    "null", "null"});
    print(tree);
    destory(tree);
    return 0;
}
