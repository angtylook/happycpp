#include <iostream>
#include <list>
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
    std::list<TreeNode*> q;
    q.push_back(root);
    while (!q.empty()) {
        auto node = q.front();
        q.pop_front();
        s.append(toStr(node)).append(",");
        if (node) {
            q.push_back(node->left);
            q.push_back(node->right);
        }
        if (std::all_of(q.begin(), q.end(),
                        [](TreeNode* n) { return n == nullptr; })) {
            break;
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
    while (!q.empty() && index < inorder.size()) {
        auto node = q.front();
        q.pop();
        if (inorder[index] != "null") {
            node->left = new TreeNode(std::stoi(inorder[index]));
            q.push(node->left);
        }
        index++;
        if (index >= inorder.size())
            break;
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

ListNode* create(const std::vector<int>& vals) {
    ListNode* head = nullptr;
    for (auto it = vals.crbegin(); it != vals.crend(); it++) {
        head = new ListNode(*it, head);
    }
    return head;
}

void print(ListNode* head) {
    std::string out("[");
    while (head != nullptr) {
        out.append(std::to_string(head->val));
        out.append(",");
        head = head->next;
    }
    if (out.back() == ',') {
        out.pop_back(); 
    }
    out.append("]");
    std::cout << out << std::endl;
}

void destroy(ListNode* head) {
    while (head != nullptr) {
        auto to_delete = head;
        head = head->next;
        delete to_delete;
    }
}
