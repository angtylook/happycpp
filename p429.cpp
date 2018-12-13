#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <vector>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        std::queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        Node* cur{nullptr};
        while (!q.empty()) {
            std::vector<int> level;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (!cur) {
                    result.push_back(level);
                    if (!q.empty())
                        q.push(nullptr);
                    break;
                }

                level.push_back(cur->val);
                for (auto it = std::begin(cur->children);
                     it != std::end(cur->children); it++) {
                    q.push(*it);
                }
            }
        }
        return result;
    }
};

int main() {
    std::vector<Node*> empty;
    auto root = new Node(
        1,
        std::vector<Node*>{new Node(3, std::vector<Node*>{new Node(5, empty),
                                                          new Node(6, empty)}),
                           new Node(2, empty), new Node(4, empty)});

    std::ostream_iterator<int> out(std::cout, " ");
    Solution sol;
    auto vis = sol.levelOrder(root);
    for (auto& vi : vis) {
        std::copy(vi.begin(), vi.end(), out);
        std::cout << std::endl;
    }
    return 0;
}
