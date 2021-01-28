#include "base/util.h"
#include <iostream>

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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        auto len_and_tail = [](ListNode* list) -> std::pair<size_t, ListNode*> {
            size_t n = 0;
            auto tail = list;
            while (list) {
                n++;
                list = list->next;
                if (list && list->next == nullptr) {
                    tail = list;
                }
            }
            return std::make_pair(n, tail);
        };

        auto [n1, t1] = len_and_tail(headA);
        auto [n2, t2] = len_and_tail(headB);
        if (n1 == 0 || n2 == 0 || t1 != t2) {
            return nullptr; // not intersect
        }

        while (n1 > n2) {
            headA = headA->next;
            n1--;
        }
        while (n2 > n1) {
            headB = headB->next;
            n2--;
        }
        // assert(n1 == n2)
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};

int main() {
    Solution sol;
    auto common = createList({8, 4, 5});
    print(common);
    std::cout << len(common) << std::endl;

    auto lista = createList({4, 1});
    auto listb = createList({5, 6, 1});
    print(lista);
    std::cout << len(lista) << std::endl;
    print(listb);
    std::cout << len(listb) << std::endl;
    auto node = sol.getIntersectionNode(lista, listb);
    if (node)
        std::cout << node->val << std::endl;

    concat(lista, common);
    concat(listb, common);

    print(lista);
    std::cout << len(lista) << std::endl;
    print(listb);
    std::cout << len(listb) << std::endl;
    node = sol.getIntersectionNode(lista, listb);
    if (node)
        std::cout << node->val << std::endl;
    return 0;
}

