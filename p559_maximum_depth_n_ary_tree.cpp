#include <iostream>
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
    int maxDepth(Node* root) {
        int depth = 0;
        if (root == nullptr) {
            return depth;
        }
        for (auto child : root->children) {
            int d = maxDepth(child);
            if (depth < d) {
                depth = d;
            }
        }
        depth++;
        return depth;
    }
};

int main() {
    Solution sol;
    Node node5;
    node5.val = 5;

    Node node6;
    node6.val = 6;

    Node node3;
    node3.val = 3;
    node3.children.push_back(&node5);
    node3.children.push_back(&node6);

    Node node2;
    node2.val = 2;

    Node node4;
    node4.val = 4;

    Node node1;
    node1.val = 1;
    node1.children.push_back(&node3);
    node1.children.push_back(&node2);
    node1.children.push_back(&node4);

    std::cout << sol.maxDepth(&node1) << std::endl;
    return 0;
}
