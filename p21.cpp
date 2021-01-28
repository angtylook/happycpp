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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode* head = nullptr;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
            head->next = nullptr;
        } else {
            head = l2;
            l2 = l2->next;
            head->next = nullptr;
        }
        ListNode* tail = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
                tail->next = nullptr;
            } else {
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
                tail->next = nullptr;
            }
        }
        if (l1 != nullptr) {
            tail->next = l1;
        }
        if (l2 != nullptr) {
            tail->next = l2;
        }
        return head;
    }
};

int main() {
    auto l1 = createList({1, 2, 4});
    auto l2 = createList({1, 3, 4});
    Solution sol;
    auto l = sol.mergeTwoLists(l1, l2);
    print(l);
    destroy(l);
    return 0;
}