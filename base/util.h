#ifndef BASE_UTIL_H_
#define BASE_UTIL_H_
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* createTree(const std::vector<std::string>& inorder);

void print(TreeNode* root);
void destory(TreeNode* root);

#endif  // BASE_UTIL_H_
