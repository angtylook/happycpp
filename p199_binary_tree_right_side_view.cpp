#include <vector>
#include <iostream>
#include <algorithm>
#include "base/util.h"

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> r;
        if (root == nullptr) {
            return r;
        }
        rightSideView(root, 0, r);
        return r;
    }

    void rightSideView(TreeNode* root, size_t depth, std::vector<int>& r) {
        depth++;
        if (r.size() < depth) {
            r.push_back(root->val);
        }
        if (root->right != nullptr) {
            rightSideView(root->right, depth, r);
        }
        if (root->left != nullptr) {
            rightSideView(root->left, depth, r);
        }
    }
};

int main() {
    Solution sol;
    auto t = createTree(std::vector<std::string>{"1", "2", "3", "null", "5", "null", "4"});
    std::cout << sol.rightSideView(t) << std::endl;
    destroy(t);

    t = createTree(std::vector<std::string>{"1", "null", "3"});
    std::cout << sol.rightSideView(t) << std::endl;
    destroy(t);

    return 0;
}