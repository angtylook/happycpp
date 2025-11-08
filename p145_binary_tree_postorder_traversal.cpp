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
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* last{nullptr};    // last visited node 用于记录上一个访问的节点的指针
        while (root != nullptr || !s.empty()) {
            /*
            1. 第一次进入时，last为空，则root不为空，将root入栈，然后root指向左子树，一直到左子树为空，
            */
            while (root != nullptr) {
                if (last == nullptr || root->right != last) {
                    s.push(root);  // case 上次访问的是左子树，将根节点入栈
                }
                if (last == nullptr || root->left != last) {
                    root = root->left;    // 只在第一次进入时产生
                } else {
                    root = root->right;   // root->left == last  cast 说明左子树已经访问完了，转向右子树
                }
            }
            // 1.1 这时左子树为空了，root为空，需要从栈中取出上一个节点，然后判断右子树是否为空，不为空则指向右子树，为空则将该节点加入结果集
            root = s.top();
            if (root->right != nullptr) {
                root = root->right;
            } else {
                last = root;         // 记录上一个访问的节点
                result.push_back(root->val);
                s.pop();
            }
        }
        return result;
    }
};

int main() {
    auto root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    auto vi = sol.postorderTraversal(root);
    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;
}
