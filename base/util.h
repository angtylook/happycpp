#ifndef BASE_UTIL_H_
#define BASE_UTIL_H_
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <chrono>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    out << "[";
    std::ostream_iterator<T> out_iter(out, ", ");
    std::copy(v.begin(), v.end(), out_iter);
    out << "]";
    return out;
}

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

TreeNode* createTree(const std::vector<std::string>& inorder);

void print(TreeNode* root);
void destroy(TreeNode* root);

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* node) : val(x), next(node) {}
};

ListNode* createList(const std::vector<int>& vals);
void print(ListNode* head);
void destroy(ListNode* head);
ListNode* concat(ListNode* list1, ListNode* list2);
size_t len(ListNode* list);

class ScopedTimer {
public:
    explicit ScopedTimer(std::string msg = "");
    ~ScopedTimer();

private:
    std::string msg_;
    std::chrono::steady_clock::time_point start_;
};

#endif  // BASE_UTIL_H_
