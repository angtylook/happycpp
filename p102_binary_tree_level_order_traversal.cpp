#include <vector>
#include <queue>

#include "base/util.h"

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> r;
        if (root == nullptr) {
            return r;
        }
        std::queue<LevelNode> q;
        q.push(LevelNode{root, r.size()});
        std::vector<int> v;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            if (node.level != r.size()) {
                r.push_back(std::move(v));
            }
            v.push_back(node.node->val);

            if (node.node->left != nullptr) {
                q.push(LevelNode{node.node->left, node.level + 1});
            }
            if (node.node->right!= nullptr) {
                q.push(LevelNode{node.node->right, node.level + 1});
            }
        }
        if (!v.empty()) {
            r.push_back(std::move(v));
        }
        return r;
    }

private:
    struct LevelNode {
        TreeNode* node;
        size_t level;
    };
};

int main() {
    Solution sol;
    auto t = createTree(std::vector<std::string>{"3", "9", "20", "null", "null", "15", "7"});
    auto r = sol.levelOrder(t);
    for (auto& e : r) {
        std::cout << e << std::endl;
    }
    return 0;
}
