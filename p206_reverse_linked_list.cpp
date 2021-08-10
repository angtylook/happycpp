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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        auto next = head->next;
        head->next = nullptr;
        while (next != nullptr) {
            auto temp = next->next;

            next->next = head;
            head = next;

            next = temp;
        }
        return head;
    }
};

int main() {
    auto head = createList({1, 2, 3, 4, 5});
    print(head);
    Solution sol;
    head = sol.reverseList(head);
    print(head);
    return 0;
}