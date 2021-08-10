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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return 0;
        }

        std::vector<int> lsums;
        std::vector<int> rsums;
        int count = 0;
        count += pathSum(root->left, sum, lsums);
        count += pathSum(root->right, sum, rsums);
        for (auto& v : lsums) {
            v += root->val;
            if (v == sum) {
                count++;
            }
        }
        for (auto& v : rsums) {
            v += root->val;
            if (v == sum) {
                count++;
            }
        }
        if (root->val == sum)
            count++;
        return count;
    }

    int pathSum(TreeNode* root, int sum, std::vector<int>& sums) {
        if (root == nullptr) {
            return 0;
        }
        std::vector<int> lsums;
        std::vector<int> rsums;
        int count = 0;
        count += pathSum(root->left, sum, lsums);
        count += pathSum(root->right, sum, rsums);
        for (auto v : lsums) {
            v += root->val;
            if (v == sum) {
                count++;
            }
            sums.push_back(v);
        }
        for (auto v : rsums) {
            v += root->val;
            if (v == sum) {
                count++;
            }
            sums.push_back(v);
        }
        if (root->val == sum)
            count++;
        sums.push_back(root->val);
        return count;
    }
};

int main() {
    Solution sol;
    auto t = createTree({"10", "5", "-3", "3", "2", "null", "11", "3", "-2", "null", "1"});
    std::cout << sol.pathSum(t, 8) << std::endl;
    return 0;
}