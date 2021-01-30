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
    ListNode* detectCycle(ListNode* head) {
        auto fast = head;
        auto slow = head;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
            if (!fast) {
                return nullptr;
            }
            fast = fast->next;
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    auto l1 = createList({3, 2, 0, -4});
    auto tail = l1;
    while (tail->next != nullptr)
        tail = tail->next;
    tail->next = l1->next;
    
    if (auto node = sol.detectCycle(l1); node != nullptr) {
        std::cout << "cycle at " << node->val << std::endl;
    } else {
        std::cout << "no cycle" << std::endl;
    }

    
    auto l2 = createList({1, 2});
    l2->next->next = l2;
    if (auto node = sol.detectCycle(l2); node != nullptr) {
        std::cout << "cycle at " << node->val << std::endl;
    } else {
        std::cout << "no cycle" << std::endl;
    }

    auto l3 = createList({1});
    if (auto node = sol.detectCycle(l3); node != nullptr) {
        std::cout << "cycle at " << node->val << std::endl;
    } else {
        std::cout << "no cycle" << std::endl;
    }
    return 0;
}
