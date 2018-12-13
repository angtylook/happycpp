#include <algorithm>
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
    std::vector<int> postorder(Node* root) {
        std::vector<int> result;
        if (root == nullptr) {
            return result;
        }

        std::stack<Node*> s;
        s.push(root);
        Node* cur{nullptr};
        Node* last{nullptr};
        while (!s.empty()) {
            cur = s.top();
            if (cur->children.empty() || cur->children.back() == last) {
                s.pop();
                result.push_back(cur->val);
                last = cur;
            } else {
                for (auto it = std::rbegin(cur->children);
                     it != std::rend(cur->children); it++) {
                    s.push(*it);
                }
            }
        }
        return result;
    }

    void preorder(Node* root, std::vector<int>& result) {
        result.push_back(root->val);
        for (auto n : root->children) {
            preorder(n, result);
        }
    }

    void postorder(Node* root, std::vector<int>& result) {
        for (auto n : root->children) {
            postorder(n, result);
        }
        result.push_back(root->val);
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
    auto vi = sol.postorder(root);
    std::copy(vi.begin(), vi.end(), out);
    std::cout << std::endl;
    return 0;
}
