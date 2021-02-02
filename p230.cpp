#include <iostream>
#include <vector>
#include <stack>

#include "base/util.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int visited = 0;
        std::stack<TreeNode*> S;
        while (!S.empty() || root != nullptr) {
            if (root != nullptr) {
                S.push(root);
                root = root->left;
            } else{
                root = S.top();
                S.pop();
                visited++;
                if (visited == k) {
                    return root->val;
                }
                root = root->right;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    auto t = createTree({"5", "3", "6", "2", "4", "null", "null", "1"});
    // expected 3
    std::cout << sol.kthSmallest(t, 3) << std::endl;
    return 0;
}

