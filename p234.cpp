#include <iostream>
#include <vector>
#include "base/util.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> vals;
        auto list = head;
        while (list) {
            vals.push_back(list->val);
            list = list->next;
        }
        std::cout << vals << std::endl;
        auto n = vals.size();
        for (size_t i = 0; i < n/2; i++) {
            if (vals[i] != vals[n - i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    auto l1 = createList({1, 1});
    std::cout << sol.isPalindrome(l1) << std::endl;
    auto l2 = createList({1, 2});
    std::cout << sol.isPalindrome(l2) << std::endl;
    auto l3 = createList({1, 2, 1});
    std::cout << sol.isPalindrome(l3) << std::endl;
    auto l4 = createList({1, 2, 2, 1});
    std::cout << sol.isPalindrome(l4) << std::endl;
    auto l5 = createList({1, 2, 3, 4});
    std::cout << sol.isPalindrome(l5) << std::endl;
    return 0;
}
