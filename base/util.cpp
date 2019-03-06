#include <iostream>
#include <queue>

#include "base/util.h"

namespace detail {
std::string toStr(TreeNode* n) {
    if (!n) {
        return "null";
    }
    return std::to_string(n->val);
};

void printTree(TreeNode* root, std::string& s) {
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        s.append(toStr(node)).append(",");
        if (node) {
            q.push(node->left);
            q.push(node->right);
        }
    }
}

}  // namespace detail

TreeNode* createTree(const std::vector<std::string>& inorder) {
    if (inorder.empty() || inorder[0] == "null") {
        return nullptr;
    }

    std::queue<TreeNode*> q;
    auto root = new TreeNode(std::stoi(inorder[0]));
    q.push(root);
    size_t index = 1;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        if (inorder[index] != "null") {
            node->left = new TreeNode(std::stoi(inorder[index]));
            q.push(node->left);
        }
        index++;
        if (inorder[index] != "null") {
            node->right = new TreeNode(std::stoi(inorder[index]));
            q.push(node->right);
        }
        index++;
    }
    return root;
}

void print(TreeNode* root) {
    std::string s("[");
    detail::printTree(root, s);
    if (s.back() == ',') {
        s.pop_back();
    }
    s.append("]");
    std::cout << s << std::endl;
}

void destory(TreeNode* root) {
    if (!root) {
        return;
    }
    destory(root->left);
    destory(root->right);
    delete root;
}
