#include <iostream>
#include "base/util.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        if (ld > rd) {
            return ld + 1;
        } else {
            return rd + 1;
        }
    }
};

int main() {
    auto t1 = createTree(
        std::vector<std::string>{"3", "9", "20", "null", "null", "15", "7"});
    Solution sol;
    std::cout << sol.maxDepth(t1) << std::endl;
    destroy(t1);
    return 0;
}
